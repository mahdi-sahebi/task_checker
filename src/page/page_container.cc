#include "page/page_container.h"


PageContainer::PageContainer()
{

}

PageContainer::~PageContainer()
{
    Clear();
}

bool PageContainer::Add(const uint16_t id, const QString& title)
{
    return false;

    //
    emit OnListChanged();
    return true;
}

bool PageContainer::Remove(const uint16_t id)
{
    return false;

    emit OnListChanged();
    return true;
}

QVariantList PageContainer::GetList()
{
    return list_;
}

void PageContainer::Clear()
{
    // TODO(MN): iterate on all list and delete the Page class
    list_.clear();
}
