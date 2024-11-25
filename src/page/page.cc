#include "page/page.h"

Page::Page() :
    title_{""},
    progress_{0.0F},
    tasks_count_{0}
{

}

Page::~Page()
{

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
