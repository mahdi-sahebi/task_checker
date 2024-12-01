#include <task_item/task_container.h>


TaskContainer::TaskContainer(QObject* parent)
{
    (void)parent;
}

TaskContainer::~TaskContainer()
{
    Clear();
}

void TaskContainer::Add(const uint8_t task_id, const QString title, const TaskItem::Task task)
{
    TaskItem* const task_item = TaskItem::Build()
            ->SetTitle(title)
            ->SetTask(task);
    if (nullptr != task_item) {
        // TODO(MN): Set task id
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
    // TOOD(MN): Iterate on list and delete the task objects
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
