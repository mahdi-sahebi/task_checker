#include "page/page.h"


Page::Page() :
    id_{0},
    title_{""},
    progress_{0.0F},
    tasks_count_{0}
{
    QObject::connect(&task_container_, &TaskContainer::progressPercentChanged, this, &Page::onProgressChanged);
    QObject::connect(&task_container_, &TaskContainer::taskListChanged, this, &Page::onTasksChecked);
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
    emit titleChanged();
}

int Page::GetTasksCount() const noexcept
{
    return tasks_count_;
}

QVariantList Page::GetTaskList()
{
    return task_container_.GetList();
}

void Page::AddTask(
    const int taskID,
    const QString title,
    const TaskItem::Task task,
    const TaskItem::Checker checker)
{
    QObject::connect(&task_container_, &TaskContainer::listChanged, this, &Page::taskListChanged);
    task_container_.AddTask(taskID, title, task, checker);
}

// TODO(MN): Remove the duplicate interface connection APIs like this.
void Page::RemoveTask(const int taskID)
{
    task_container_.RemoveTask(taskID);
}

void Page::ClearTasks() noexcept
{
    task_container_.ClearTasks();
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
    if (0 == task_container_.GetTasksCount()) {
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

float Page::GetProgressPercent() const noexcept
{
    return task_container_.GetProgressPercent();
}
