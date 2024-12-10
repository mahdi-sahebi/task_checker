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
    Q_PROPERTY(unsigned int tasks_count READ GetTasksCount NOTIFY OnTasksCountChanged)
    Q_PROPERTY(QVariantList taskList READ GetTaskList NOTIFY onTaskListChanged)
    Q_PROPERTY(float progress READ getProgress NOTIFY progressChanged)

public:
    Page();
    Page(const Page&) = delete;
    Page& operator=(const Page&) = delete;
    ~Page();

    QString GetTitle() const noexcept;
    void SetTitle(const QString& title);
    unsigned int GetTasksCount();

    QVariantList GetTaskList();
    void AddTask(const uint8_t task_id,
                 const QString title,
                 const TaskItem::Task task,
                 const TaskItem::Checker checker);
    void RemoveTask(const uint8_t task_id);
    void ClearTasks();

    void SetID(const unsigned int id) noexcept;
    Q_INVOKABLE unsigned int GetID() const noexcept;
    Q_INVOKABLE void CheckAllTasks() const noexcept;
    float getProgress() const noexcept;

signals:
    void OnTitleChanged();
    void progressChanged();
    void OnTasksCountChanged();
    void onTaskListChanged();
    // TOOD(MN): Signal of on page enter/exit/complete(all tasks done)

private slots:
    void onProgressChanged();

private:
    uint32_t id_;// TODO(MN): Hold it unique. use builder
    QString title_;
    float progress_;
    uint8_t tasks_count_;
    TaskContainer task_container_;
};


#endif /* PAGE_H_ */
