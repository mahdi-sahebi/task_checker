#include "page/page.h"

Page::Page() :
    id_{0},
    title_{""},
    progress_{0.0F},
    tasks_count_{0}//,
//    task_container_{nullptr}
{

}

Page::~Page()
{
    ClearTasks();
}

QString Page::GetTitle() const noexcept
{
    return title_;
}

void Page::SetTitle(const QString& title)
{
    title_ = title;
    emit OnTitleChanged();
}

float Page::GetProgress() const noexcept
{
    return 0.0F;
}

void Page::SetProgress(const float& percent)
{
    progress_ = percent;
    emit OnProgressChanged();
}

uint8_t Page::GetTasksCount()
{
    return tasks_count_;
}

void Page::SetTasksCount(const uint8_t& count)
{
    tasks_count_ = count;
    emit OnTasksCountChanged();
}

QVariantList Page::GetTaskList()
{
    return task_container_.GetList();
}

void Page::AddTask(const uint8_t task_id, const QString title, const TaskItem::Task task)
{
    QObject::connect(&task_container_, &TaskContainer::OnListChanged, this, &Page::onTaskListChanged);
    // TODO(MN): Connect arguments
    // TODO(MN): Use base interface
    task_container_.Add(task_id, title, task);
}

void Page::RemoveTask(const uint8_t task_id)
{
    // TODO(MN): Use correct concept of task id instead of index
    task_container_.Remove(task_id);
}

void Page::ClearTasks()
{
    task_container_.Clear();
}

void Page::SetID(const uint32_t id) noexcept
{
    id_ = id;
}

uint32_t Page::GetID() const noexcept
{
    return id_;
}
