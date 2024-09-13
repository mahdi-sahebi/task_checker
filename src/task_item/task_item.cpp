#include "task_item/task_item.h"

TaskItem::TaskItem(QObject* parent)
{
  (void)parent;
  SetTitle("");
  SetState(State::CHECK);
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

}

void TaskItem::SetState(const State state)
{
  QString files[] =
  {
    [static_cast<uint32_t>(State::CHECK)  ] = "assets/check.png",
    [static_cast<uint32_t>(State::WAIT)   ] = "assets/wait.png",
    [static_cast<uint32_t>(State::FAIL)   ] = "assets/false.png",
    [static_cast<uint32_t>(State::SUCCESS)] = "assets/true.png",
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
