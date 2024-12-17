/* TOOD(MN): Signal of on page enter/exit/complete(all tasks done)
 * TODO(MN): Hold ID unique. use builder
 *
 */

#ifndef PAGE_H_
#define PAGE_H_

#include <cstdint>
#include <functional>
#include <QString>
#include <QObject>
#include <QVariantList>
#include "task_item/task_container_interface.h"
#include "task_item/task_container.h"


class Page : public TaskContainerInterface
{
    Q_OBJECT
    Q_PROPERTY(QString title READ GetTitle WRITE SetTitle NOTIFY titleChanged)
    Q_PROPERTY(unsigned int tasks_count READ GetTasksCount NOTIFY tasksCountChanged)
    Q_PROPERTY(QVariantList taskList READ GetTaskList NOTIFY taskListChanged)
    Q_PROPERTY(float progress READ GetProgressPercent NOTIFY progressChanged)

public:
    Page();
    Page(const Page&) = delete;
    Page& operator=(const Page&) = delete;
    ~Page();

    Q_INVOKABLE void AddTask(const int taskID,
                 const QString title,
                 const TaskItem::Task task,
                 const TaskItem::Checker checker) override;
    Q_INVOKABLE void RemoveTask(const int taskID) override;
    Q_INVOKABLE void ClearTasks() noexcept override;
    Q_INVOKABLE int GetTasksCount() const noexcept override;
    float GetProgressPercent() const noexcept override;

    QString GetTitle() const noexcept;
    void SetTitle(const QString& title);

    QVariantList GetTaskList();
    void SetID(const unsigned int id) noexcept;
    unsigned int GetID() const noexcept;
    Q_INVOKABLE void CheckTasks() noexcept;

signals:
    void titleChanged();
    void progressChanged();
    void tasksCountChanged();
    void checkTasksBegan();
    void checkTasksEnded();

private slots:
    void onProgressChanged();
    void onTasksChecked();

private:
    uint32_t id_;
    QString title_;
    float progress_;
    uint8_t tasks_count_;
    TaskContainer task_container_;

};


#endif /* PAGE_H_ */
