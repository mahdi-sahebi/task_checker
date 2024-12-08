#include <task_item/task_container.h>


TaskContainer::TaskContainer(QObject* parent)
{
    (void)parent;
}

TaskContainer::~TaskContainer()
{
    Clear();
}

void TaskContainer::Add(
        const uint8_t task_id,
        const QString title,
        const TaskItem::Task task,
        const TaskItem::Checker checker)
{
    TaskItem* const task_item = TaskItem::Build()
            ->SetTitle(title)
            ->SetTask(task, checker);

    if (nullptr != task_item) {
        task_item->SetID(task_id);// TODO(MN): Keep it unique
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
    uint32_t last_index = static_cast<uint32_t>(list_.size());

    while (last_index--) {
        Remove(last_index);
    }
}

int TaskContainer::GetCount()
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

void TaskContainer::CheckAllTasks() const noexcept
{
    uint32_t last_index = static_cast<uint32_t>(list_.size());

    while (last_index--) {
        TaskItem* const task = list_[last_index].value<TaskItem*>();
        if (nullptr == task) {
            continue;
        }

        task->Check();
    }
}

