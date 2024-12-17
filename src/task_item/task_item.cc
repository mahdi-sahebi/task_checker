#include <QDebug>
#include "task_item/task_item.h"

#include <chrono>
#include <thread>

using namespace std;

TaskItem::TaskItem(QObject* parent) :
    isEnabled_{true}, task_{nullptr}, checker_{nullptr}, id_{0}
{
  (void)parent;
  SetState(State::kFail);
}

TaskItem::TaskItem(TaskItem&& other)
{
  *this = std::move(other);
}

TaskItem& TaskItem::operator=(TaskItem&& other)
{
  if (this != &other) {
      id_ = std::move(other.id_);
      isEnabled_ = std::move(other.isEnabled_);
      title_ = std::move(other.title_);
      imagePath_ = std::move(other.imagePath_);
      task_ = std::move(other.task_);
      checker_ = std::move(other.checker_);
  }

  return *this;
}

void TaskItem::SetID(const uint32_t id)
{
    id_ = id;
}

uint32_t TaskItem::GetID()
{
    return id_;
}

QString TaskItem::GetTitle()
{
  return title_;
}

void TaskItem::SetTitle(const QString& title)
{
  title_ = title;
  emit titleChanged();
}

void TaskItem::CheckAsync()
{
    // TODO(MN): Thread safe(Not only for ui button)
    SetEnable(false);
    SetState(State::kWait);

    std::thread([this](){
        // TODO(MN): Handle timeout
        const auto isDone = checker_();
        SetState(isDone ? State::kDone : State::kFail);
        SetEnable(true);
        emit stateChanged(id_, isDone);
    }).detach();
}

bool TaskItem::Check()
{
    // TODO(MN): Thread safe(Not only for ui button)
    SetEnable(false);
    SetState(State::kWait);

    // TODO(MN): Handle timeout
    const auto isDone = checker_();
    SetState(isDone ? State::kDone : State::kFail);
    SetEnable(true);
    emit stateChanged(id_, isDone);

    return isDone;
}

void TaskItem::Run()
{
    SetEnable(false);
    SetState(State::kWait);

    std::thread([this](){
        // TODO(MN): Handle timeout
        task_();
        const auto isDone = checker_();
        SetState(isDone ? State::kDone : State::kFail);
        SetEnable(true);
        emit stateChanged(id_, isDone);
    }).detach();
}

void TaskItem::SetState(const State state)
{
  QString files[] =
  {
    [static_cast<uint32_t>(State::kWait)] = "assets/wait.png",
    [static_cast<uint32_t>(State::kFail)] = "assets/false.png",
    [static_cast<uint32_t>(State::kDone)] = "assets/true.png",
  };

  SetImagePath(files[static_cast<uint32_t>(state)]);
}

QString TaskItem::GetImagePath()
{
  return imagePath_;
}

void TaskItem::SetImagePath(const QString& imagePath)
{
  imagePath_ = imagePath;
  emit imagePathChanged();
}

bool TaskItem::IsEnabled()
{
    return isEnabled_;
}

TaskItem* TaskItem::SetEnable(const bool enable)
{
    isEnabled_ = enable;
    emit enableChanged();
    return this;
}

TaskItem* TaskItem::SetTask(const Task task, const Checker checker)
{
    if ((nullptr == task) || (nullptr == checker)){
        qDebug() << "[TaskItem] Task callback hasn't been set";
        return nullptr;
    }

    task_ = task;
    checker_ = checker;
    return this;
}

TaskItem::Builder& TaskItem::Builder::SetID(const ID id) noexcept
{
  id_ = id;
  return *this;
}

TaskItem::Builder& TaskItem::Builder::SetTask(const Task task, const Checker checker) noexcept
{
  task_ = task;
  checker_ = checker;
  return *this;
}

TaskItem::Builder& TaskItem::Builder::SetTitle(const QString title) noexcept
{
  title_ = title;
  return *this;
}

TaskItem* TaskItem::Builder::Build()
{
  TaskItem* taskItem = new TaskItem();

  if (nullptr != taskItem) {
      taskItem->SetTitle(title_);
      taskItem->SetTask(task_, checker_);
      taskItem->SetID(id_);
      taskItem->SetEnable(false);
  }

  return taskItem;
}
