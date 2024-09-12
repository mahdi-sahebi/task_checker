#include "task_item.h"

TaskItem::TaskItem(QObject* parent)
{
  (void)parent;
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

