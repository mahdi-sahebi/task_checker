#include "page/page.h"

Page::Page() :
    title_{""},
    progress_{0.0F},
    tasks_count_{0},
    task_container_{nullptr}
{

}

Page::~Page()
{
    // TODO(MN): Task container
}

QString Page::GetTitle()
{
    return title_;
}

void Page::SetTitle(const QString& title)
{
    title_ = title;
    emit OnTitleChanged();
}

float Page::GetProgress()
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

void Page::AddTask(const uint8_t id, const QString title, std::function<void()> task)
{
    // TODO(MN): Connect arguments
    task_container_->Add();
}

void Page::RemoveTask(const uint8_t id)
{
    // TODO(MN): Use correct concept of task id instead of index
    task_container_->Remove(id);
}

void Page::ClearTasks()
{
    task_container_->Clear();
}
