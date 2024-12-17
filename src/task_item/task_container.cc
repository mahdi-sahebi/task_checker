#include <task_item/task_container.h>


TaskContainer::TaskContainer(QObject* parent) :
    progressPercent_{0}
{
    (void)parent;
}

TaskContainer::~TaskContainer()
{
    ClearTasks();
}

void TaskContainer::AddTask(
    const int taskID,
    const QString title,
    const TaskItem::Task task,
    const TaskItem::Checker checker)
{
    TaskItem* const taskItem = TaskItem::Builder()
        .SetID(taskID)
        .SetTask(task, checker)
        .SetTitle(title)
        .Build();

    if (nullptr != taskItem) {
      // TODO(MN): Handle unique list and exceptions
      isDone_[taskID] = false;

      list_.append(QVariant::fromValue(taskItem));

      QObject::connect(taskItem, &TaskItem::stateChanged, this, &TaskContainer::onTaskStateChanged);
      emit listChanged();
    }
}

void TaskContainer::RemoveTask(const int taskID)// TODO(MN): Correct data type
{
    // TODO(MN): How to use map for QVariantList to not linear search?
    for (uint32_t index = 0; index < static_cast<uint32_t>(list_.size()); index++) {
        TaskItem* const task_item = list_[index].value<TaskItem*>();

        if ((nullptr == task_item) || (task_item->GetID() != static_cast<uint32_t>(taskID))) {
            continue;
        }

        // TODO(MN): Check existance and handle exceptions
        isDone_.erase(isDone_.find(taskID));

        QObject::disconnect(task_item, &TaskItem::stateChanged, this, &TaskContainer::onTaskStateChanged);
        delete task_item;

        list_.removeAt(index);
        emit listChanged();
    }
}

void TaskContainer::ClearTasks() noexcept
{
    uint32_t last_index = static_cast<uint32_t>(list_.size());

    while (last_index--) {
        RemoveTask(last_index);
    }
}

int TaskContainer::GetTasksCount() const noexcept
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
        emit listChanged();
    }
}

void TaskContainer::CheckTasks() noexcept
{
    //TODO(MN): Run all task checker on separated thread

    is_run_.clear();
    for (auto& [taskID, isDone]: isDone_) {
        isDone = false;
        is_run_[taskID] = true;
    }


    uint32_t last_index = static_cast<uint32_t>(list_.size());

    while (last_index--) {
        TaskItem* const taskItem = list_[last_index].value<TaskItem*>();
        if (nullptr == taskItem) {
            continue;
        }

        taskItem->CheckAsync();
    }
}

void TaskContainer::onTaskStateChanged(const TaskItem::ID taskID, const bool isDone)
{
    isDone_[taskID] = isDone;
    CalculateProgress();

    is_run_[taskID] = false;
    CheckTasksDone();
}

void TaskContainer::CalculateProgress()
{
    uint32_t doneCounter{0};

    for (const auto& [taskID, isDone] : isDone_) {
        doneCounter += static_cast<uint8_t>(isDone);
    }

    const float percent = static_cast<float>(doneCounter) / isDone_.size();

    if (percent != progressPercent_) {
        progressPercent_ = percent;
        emit progressPercentChanged();
    }
}

void TaskContainer::CheckTasksDone()
{
    bool all_done = true;

    for (auto& [taskID, is_run]: is_run_) {
        if (true == is_run) {
            all_done = false;
            break;
        }
    }

    if (all_done) {
        emit taskListChanged();
    }
}

float TaskContainer::GetProgressPercent() const noexcept
{
    return progressPercent_;
}
