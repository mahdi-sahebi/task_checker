#include <task_item/task_container.h>


TaskContainer::TaskContainer(QObject* parent)
{
    (void)parent;
}

TaskContainer::~TaskContainer()
{
}

void TaskContainer::Add()
{
    TaskItem* const task_item = new TaskItem("hi", [](){return false;});
    list_.append(QVariant::fromValue(task_item));
    emit OnListChanged();
}

void TaskContainer::Remove(const uint32_t index)
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
