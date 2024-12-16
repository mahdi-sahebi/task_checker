#ifndef TASK_CONTAINER_H_
#define TASK_CONTAINER_H_

#include <map>
#include <QObject>
#include <QString>
#include <QVariantList>
#include "task_item.h"
#include "task_container_interface.h"


class TaskContainer : public TaskContainerInterface
{
    Q_OBJECT
    Q_PROPERTY(QVariantList list READ GetList WRITE SetList NOTIFY listChanged)
    Q_PROPERTY(float progressPercent READ GetProgressPercent NOTIFY progressPercentChanged)

public:
    explicit TaskContainer(QObject* parent = nullptr);
    TaskContainer(const TaskContainer& other) = delete;
    ~TaskContainer();

    Q_INVOKABLE void AddTask(const int taskID, // TODO(MN): Optimize arg count
                             const QString title,
                             const TaskItem::Task task,
                             const TaskItem::Checker checker) override;
    Q_INVOKABLE void RemoveTask(const int taskID) override;
    Q_INVOKABLE void ClearTasks() noexcept override;
    Q_INVOKABLE int GetTasksCount() const noexcept override;
    float GetProgressPercent() const noexcept override;
    QVariantList GetList();
    void SetList(const QVariantList& list);// TODO(MN): Private
    void CheckTasks() noexcept;

signals:
    void listChanged();
    void progressPercentChanged();

public slots:
    void onTaskStateChanged(const TaskItem::ID taskID, const bool is_done);

private:
    QVariantList list_;
    std::map<TaskItem::ID, bool> is_done_;// TODO(MN): Rename to ...list_
    std::map<TaskItem::ID, bool> is_run_;
    float progressPercent_;

    void CalculateProgress();
    void CheckTasksDone();
};


#endif /* TASK_CONTAINER_H_ */
