#ifndef TASK_CONTAINER_INTERFACE_H_
#define TASK_CONTAINER_INTERFACE_H_

#include <QObject>
#include <QString>
#include "task_item.h"


class TaskContainerInterface : public QObject
{
    Q_OBJECT

public:
    explicit TaskContainerInterface(QObject* parent = nullptr) : QObject(parent){}
    virtual ~TaskContainerInterface() = default;

    // TODO(MN): Optimize arg count
    virtual Q_INVOKABLE void AddTask(const int taskID,
                                     const QString title,
                                     const TaskItem::Task task,
                                     const TaskItem::Checker checker) = 0;
    virtual Q_INVOKABLE void RemoveTask(const int taskID) = 0;
    virtual Q_INVOKABLE void ClearTasks() noexcept = 0;
    virtual Q_INVOKABLE int GetTasksCount() const noexcept = 0;
    virtual float GetProgressPercent() const noexcept = 0;

signals:
    void taskListChanged();

};

#endif /* TASK_CONTAINER_INTERFACE_H_ */
