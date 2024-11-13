#include <task_item/task_container.h>


TaskContainer::TaskContainer(QObject* parent)
{
    (void)parent;
}

TaskContainer::~TaskContainer()
{
    Clear();
}

void TaskContainer::Add()
{
    TaskItem* const task_item = TaskItem::Build()
            ->SetTitle("Example")
            ->SetTask([]()
        {
            static bool result = 0;
            result = !result;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return result;
        });
    if (nullptr != task_item) {
        list_.append(QVariant::fromValue(task_item));

        emit OnListChanged();
    }
}

void TaskContainer::Remove(const unsigned int index)
{
    if (index <= static_cast<uint32_t>(list_.size() - 1)) {
        TaskItem* const task_item = list_[index].value<TaskItem*>();
        if (nullptr != task_item) {
            delete task_item;
        }

        list_.removeAt(index);

        emit OnListChanged();
    }
}

void TaskContainer::Clear()
{
    uint32_t index = list_.size();

    while (index--) {
        Remove(index);
    }
}

Q_INVOKABLE int TaskContainer::GetCount()
{
    return list_.size();
}

QVariantList TaskContainer::GetList()
{
    return list_;
}

void TaskContainer::SetList(const QVariantList& list)
{
    if (list != list_) {
        list_ = list;
        emit OnListChanged();
    }
}
