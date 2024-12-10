#include <task_item/task_container.h>


TaskContainer::TaskContainer(QObject* parent) :
    progressPercent_{0}
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
        // TODO(MN): Handle unique list and exceptions
        is_done_[task_id] = false;

        task_item->SetID(task_id);// TODO(MN): Keep it unique
        list_.append(QVariant::fromValue(task_item));

        QObject::connect(task_item, &TaskItem::OnStateChanged, this, &TaskContainer::taskStateChanged);
        emit OnListChanged();
    }
}

void TaskContainer::Remove(const unsigned int task_id)// TODO(MN): Correct data type
{
    // TODO(MN): How to use map for QVariantList to not search?
    for (uint32_t index = 0; index < static_cast<uint32_t>(list_.size()); index++) {
        TaskItem* const task_item = list_[index].value<TaskItem*>();

        if ((nullptr == task_item) || (task_item->GetID() != task_id)) {
            continue;
        }

        // TODO(MN): Check existance and handle exceptions
        is_done_.erase(is_done_.find(task_id));

        QObject::disconnect(task_item, &TaskItem::OnStateChanged, this, &TaskContainer::taskStateChanged);
        delete task_item;

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

void TaskContainer::CheckTasks() const noexcept
{
    //TODO(MN): Run all task checker on separated thread
//    uint32_t passed_count = 0;
//    uint32_t last_index = static_cast<uint32_t>(list_.size());

//    while (last_index--) {
//        TaskItem* const task = list_[last_index].value<TaskItem*>();
//        if (nullptr == task) {
//            continue;
//        }

//        task->CheckAsync();
//    }
}

void TaskContainer::taskStateChanged(const TaskItem::ID task_id, const bool is_done)
{
    is_done_[task_id] = is_done;
    CalculateProgress();
}

void TaskContainer::CalculateProgress()
{
    uint32_t doneCounter{0};

    for (const auto& [task_id, is_done] : is_done_) {
        doneCounter += static_cast<uint8_t>(is_done);
    }

    float percent = static_cast<float>(doneCounter) / is_done_.size();

    if (percent != progressPercent_) {
        progressPercent_ = percent;
        emit progressPercentChanged();
    }
}

float TaskContainer::getProgressPercent() const noexcept
{
    return progressPercent_;
}
