#include "page/page.h"

Page::Page() :
    id_{0},
    title_{""},
    progress_{0.0F},
    tasks_count_{0}{

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
    return 0.11F;
}

void Page::SetProgress(const float& percent)
{
    progress_ = percent;
    emit OnProgressChanged();
}

unsigned int Page::GetTasksCount()
{
    return tasks_count_;
}

QVariantList Page::GetTaskList()
{
    return task_container_.GetList();
}

void Page::AddTask(
        const uint8_t task_id,
        const QString title,
        const TaskItem::Task task,
        const TaskItem::Checker checker)
{
    QObject::connect(&task_container_, &TaskContainer::OnListChanged, this, &Page::onTaskListChanged);
    // TODO(MN): Connect arguments
    // TODO(MN): Use base interface
    task_container_.Add(task_id, title, task, checker);
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

void Page::SetID(const unsigned int id) noexcept
{
    id_ = id;
}

unsigned int Page::GetID() const noexcept
{
    return id_;
}

void Page::CheckAllTasks() const noexcept
{
    task_container_.CheckAllTasks();
}
