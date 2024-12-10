#include <QDebug>
#include "task_item/task_item.h"

#include <chrono>
#include <thread>

using namespace std;

TaskItem::TaskItem(QObject* parent) :
    is_enabled_{true}, task_{nullptr}, checker_{nullptr}, id_{0}
{
  (void)parent;
  SetState(State::kFail);
}

TaskItem::~TaskItem()
{

}

void TaskItem::SetID(const uint32_t id)
{
    id_ = id;
}

uint32_t TaskItem::GetID()
{
    return id_;
}

TaskItem* TaskItem::Build()
{
    return new TaskItem();
}

QString TaskItem::GetTitle()
{
  return title_;
}

TaskItem* TaskItem::SetTitle(const QString& title)
{
  title_ = title;
  emit OnTitleChanged();
  return this;
}

void TaskItem::CheckAsync()
{
    // TODO(MN): Thread safe(Not only for ui button)
    SetEnable(false);
    SetState(State::kWait);

    std::thread([this](){
        // TODO(MN): Handle timeout
        const State state = checker_() ? State::kDone : State::kFail;
        SetState(state);
        SetEnable(true);
    }).detach();
}

bool TaskItem::Check()
{
    // TODO(MN): Thread safe(Not only for ui button)
    SetEnable(false);
    SetState(State::kWait);

    // TODO(MN): Handle timeout
    const auto is_done = checker_();
    SetState(is_done ? State::kDone : State::kFail);
    SetEnable(true);
    emit OnStateChanged(id_, is_done);

    return is_done;
}

void TaskItem::Run()
{
    SetEnable(false);
    SetState(State::kWait);

    std::thread([this](){
        // TODO(MN): Handle timeout
        task_();
        const auto is_done = checker_();
        SetState(is_done ? State::kDone : State::kFail);
        SetEnable(true);
        emit OnStateChanged(id_, is_done);
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
  return image_path_;
}

void TaskItem::SetImagePath(const QString& image_path)
{
  image_path_ = image_path;
  emit OnImagePathChanged();
}

bool TaskItem::IsEnabled()
{
    return is_enabled_;
}

TaskItem* TaskItem::SetEnable(const bool enable)
{
    is_enabled_ = enable;
    emit onEnableChanged();
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
