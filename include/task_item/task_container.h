#ifndef TASK_CONTAINER_H_
#define TASK_CONTAINER_H_

#include <map>
#include <QObject>
#include <QVariantList>
#include "task_item.h"


// TODO(MN): Apply google naming convension
class TaskContainer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList list READ GetList WRITE SetList NOTIFY OnListChanged)
    Q_PROPERTY(float progressPercent READ getProgressPercent NOTIFY progressPercentChanged)

public:
    explicit TaskContainer(QObject* parent = nullptr);
    TaskContainer(const TaskContainer& other) = delete;
    ~TaskContainer();
    Q_INVOKABLE void Add(const uint8_t task_id, // TODO(MN): Optimize arg count
                         const QString title,
                         const TaskItem::Task task,
                         const TaskItem::Checker checker);
    Q_INVOKABLE void Remove(const unsigned int task_id);
    Q_INVOKABLE void Clear();
    Q_INVOKABLE int GetCount();
    QVariantList GetList();
    void SetList(const QVariantList& list);// TODO(MN): Private
    void CheckTasks() noexcept;
    float getProgressPercent() const noexcept;

signals:
    void OnListChanged();
    void progressPercentChanged();
    void tasksChecked();

public slots:
    void taskStateChanged(const TaskItem::ID task_id, const bool is_done);

private:
    QVariantList list_;
    std::map<TaskItem::ID, bool> is_done_;// TODO(MN): Rename to ...list_
    std::map<TaskItem::ID, bool> is_run_;
    float progressPercent_;

    void CalculateProgress();
    void CheckTasksDone();
};


#endif /* TASK_CONTAINER_H_ */
