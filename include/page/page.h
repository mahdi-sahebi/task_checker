#ifndef PAGE_H_
#define PAGE_H_

#include <cstdint>
#include <functional>
#include <QString>
#include <QObject>
#include <QVariantList>
#include <task_item/task_container.h>

class Page : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ GetTitle WRITE SetTitle NOTIFY OnTitleChanged)
    Q_PROPERTY(float progress READ GetProgress NOTIFY OnProgressChanged)
    Q_PROPERTY(uint8_t tasks_count READ GetTasksCount NOTIFY OnTasksCountChanged)
    Q_PROPERTY(QVariantList taskList READ GetTaskList NOTIFY onTaskListChanged)

public:
    Page();
    Page(const Page&) = delete;
    Page& operator=(const Page&) = delete;
    ~Page();

    QString GetTitle() const noexcept;
    void SetTitle(const QString& title);
    float GetProgress() const noexcept;
    uint8_t GetTasksCount();

    QVariantList GetTaskList();
    void AddTask(const uint8_t task_id,
                 const QString title,
                 const TaskItem::Task task,
                 const TaskItem::Checker checker);
    void RemoveTask(const uint8_t task_id);
    void ClearTasks();

    void SetID(const uint32_t id) noexcept;
    Q_INVOKABLE uint32_t GetID() const noexcept;

signals:
    void OnTitleChanged();
    void OnProgressChanged();
    void OnTasksCountChanged();
    void onTaskListChanged();

private:
    uint32_t id_;// TODO(MN): Hold it unique. use builder
    QString title_;
    float progress_;
    uint8_t tasks_count_;
    TaskContainer task_container_;

    void SetProgress(const float& percent);
    void SetTasksCount(const uint8_t& count);

};


#endif /* PAGE_H_ */
