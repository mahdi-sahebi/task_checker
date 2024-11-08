#ifndef TASK_CONTAINER_H_
#define TASK_CONTAINER_H_

#include <QObject>
#include <QVariantList>
#include "task_item.h"


class TaskContainer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList list READ GetList WRITE SetList NOTIFY OnListChanged)

public:
    explicit TaskContainer(QObject* parent = nullptr);
    ~TaskContainer();
    Q_INVOKABLE void Add();
    Q_INVOKABLE void Remove(const uint32_t index);
    QVariantList GetList();
    void SetList(const QVariantList& list);

signals:
    void OnListChanged();

private:
    QVariantList list_;
};


#endif /* TASK_CONTAINER_H_ */
