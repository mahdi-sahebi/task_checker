#include "task_item/task_item.h"


TaskItem::TaskItem(QObject* parent)
{
  (void)parent;
  SetTitle("");
  SetState(State::kIdle);
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
    SetState(State::kWait);

    // TODO(MN): Run on another thread as non-blocking

    const State state = State::kFail; // TODO(MN): Call from callback
    SetState(state);
}

void TaskItem::SetState(const State state)
{
  QString files[] =
  {
    [static_cast<uint32_t>(State::kIdle)] = "assets/check.png",
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
