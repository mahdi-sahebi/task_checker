#ifndef TASK_CONTAINER_H_
#define TASK_CONTAINER_H_

#include <QObject>
#include <QVariantList>
#include "task_item.h"


// TODO(MN): Apply google naming convension
class TaskContainer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList list READ GetList WRITE SetList NOTIFY OnListChanged)

public:
    explicit TaskContainer(QObject* parent = nullptr);
    TaskContainer(const TaskContainer& other) = delete;
    ~TaskContainer();
    Q_INVOKABLE void Add(const uint8_t task_id, // TODO(MN): Optimize arg count
                         const QString title,
                         const TaskItem::Task task,
                         const TaskItem::Checker checker);
    Q_INVOKABLE void Remove(const unsigned int index);
    Q_INVOKABLE void Clear();
    Q_INVOKABLE int GetCount();
    QVariantList GetList();
    void SetList(const QVariantList& list);// TODO(MN): Private
    void CheckAllTasks() const noexcept;

signals:
    void OnListChanged();

private:
    QVariantList list_;
};


#endif /* TASK_CONTAINER_H_ */
