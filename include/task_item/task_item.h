#ifndef TASK_ITEM_H_
#define TASK_ITEM_H_

#include <cstdbool>
#include <string>
#include <functional>
#include <thread>
#include <QObject>
#include <QString>

// namespace Task::Item
class TaskItem : public QObject
{
Q_OBJECT
Q_PROPERTY(QString title READ GetTitle WRITE SetTitle NOTIFY OnTitleChanged)
Q_PROPERTY(QString image_path READ GetImagePath WRITE SetImagePath NOTIFY OnImagePathChanged)
Q_PROPERTY(bool is_enabled READ IsEnabled() WRITE SetEnable NOTIFY OnEnableChanged)

public:
  enum class State
  {
    kWait,
    kFail,
    kDone
  };

  using Task = std::function<bool()>;

  explicit TaskItem(QObject* parent = nullptr);
  TaskItem(const TaskItem& other) = delete;
  ~TaskItem();

  static TaskItem* Build();

  QString GetTitle();
  TaskItem* SetTitle(const QString& title);
  QString GetImagePath();
  void    SetImagePath(const QString& image_path);
  bool    IsEnabled();
  TaskItem* SetEnable(const bool enable);
  TaskItem* SetTask(const Task task);
  Q_INVOKABLE void Check();

signals:
  void OnTitleChanged();
  void OnImagePathChanged();
  void OnEnableChanged();

private:
  bool is_enabled_;
  QString title_;
  QString image_path_;
  Task task_;

  void SetState(const State state);
};

#endif /* TASK_ITEM_H_ */
