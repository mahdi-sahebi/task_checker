#include "page/page.h"
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
    auto page = new Page();// TODO(MN): Use builder
    if (nullptr == page) {
        return false;
    }

    page->SetID(id);
    page->SetTitle(title);
    list_.append(QVariant::fromValue(page));
    emit OnListChanged();
    return true;
}

bool PageContainer::Remove(const uint16_t id)
{
    const uint32_t size = static_cast<uint32_t>(list_.size());

    for (uint32_t index = 0; index < size; index++) {
        const auto page = list_[index].value<Page*>();

        if (page->GetID() == id) {
            continue;
        }

        delete page;
        list_.removeAt(index);
        emit OnListChanged();
        return true;
    }

    return false;
}

QVariantList PageContainer::GetList()
{
    return list_;
}

void PageContainer::Clear()
{
    uint32_t index = static_cast<uint32_t>(list_.size());

    while (index--) {
        const auto page = list_[index].value<Page*>();
        delete page;

        list_.removeAt(index);
    }

    emit OnListChanged();
}
