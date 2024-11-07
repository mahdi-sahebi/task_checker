#include "task_item/task_item.h"

using namespace std;

TaskItem::TaskItem(string title, const Task& task, QObject* parent) :
    task_{task}, is_enabled_{true}
{
  (void)parent;
  SetTitle(QString::fromStdString(title));
  SetState(State::kFail);
}

TaskItem::~TaskItem()
{

}

QString TaskItem::GetTitle()
{
  return title_;
}

void TaskItem::SetTitle(const QString& title)
{
  title_ = title;
  emit OnTitleChanged();
}

void TaskItem::Check()
{
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

void TaskItem::SetEnable(const bool enable)
{
    is_enabled_ = enable;
    emit OnEnableChanged();
}
