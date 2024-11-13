#include <QDebug>
#include "task_item/task_item.h"

#include <chrono>
#include <thread>

using namespace std;

TaskItem::TaskItem(QObject* parent) :
    is_enabled_{true}, task_{nullptr}
{
  (void)parent;
  SetState(State::kFail);
}

TaskItem::~TaskItem()
{

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

void TaskItem::Check()
{
    if (nullptr == task_) {
        qDebug() << "[TaskItem] Callback hasn't been set";
        return;
    }

    SetEnable(false);
    SetState(State::kWait);

    std::thread([this](){
        // TODO(MN): Handle timeout
        const State state = task_() ? State::kDone : State::kFail;
        SetState(state);
        SetEnable(true);
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
    emit OnEnableChanged();
    return this;
}

TaskItem* TaskItem::SetTask(const Task task)
{
    task_ = task;
    return this;
}
