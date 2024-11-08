#ifndef TASK_CONTAINER_H_
#define TASK_CONTAINER_H_

#include <QObject>
#include <QVariantList>


class TaskContainer : public QObject
{
    Q_OBJECT
public:
    explicit TaskContainer(QObject* parent = nullptr);

private:
    QVariantList list_;
};


#endif /* TASK_CONTAINER_H_ */
