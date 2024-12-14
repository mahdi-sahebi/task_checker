#include "page/page.h"


Page::Page() :
    id_{0},
    title_{""},
    progress_{0.0F},
    tasks_count_{0}
{
    QObject::connect(&task_container_, &TaskContainer::progressPercentChanged, this, &Page::onProgressChanged);
    QObject::connect(&task_container_, &TaskContainer::tasksChecked, this, &Page::onTasksChecked);
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

unsigned int Page::GetTasksCount() const noexcept
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

// TODO(MN): Remove the duplicate interface connection APIs like this.
// Use a get task container and call direct in QML file
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

void Page::CheckTasks() noexcept
{
    // TODO(MN): Thread-safety
    if (0 == task_container_.GetCount()) {
        return;
    }

    emit checkTasksBegan();
    task_container_.CheckTasks();
}

void Page::onProgressChanged()
{
    emit progressChanged();
}

void Page::onTasksChecked()
{
    emit checkTasksEnded();
}

float Page::getProgress() const noexcept
{
    return task_container_.getProgressPercent();
}
