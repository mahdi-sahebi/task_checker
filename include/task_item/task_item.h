#ifndef TASK_ITEM_H_
#define TASK_ITEM_H_

#include <cstdint>
#include <string>
#include <functional>
#include <thread>
#include <QObject>
#include <QString>

// namespace Task::Item
// Thread-safety for all APIs
class TaskItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ GetTitle WRITE SetTitle NOTIFY titleChanged)
    Q_PROPERTY(QString imagePath READ GetImagePath WRITE SetImagePath NOTIFY imagePathChanged)
    Q_PROPERTY(bool isEnabled READ IsEnabled() WRITE SetEnable NOTIFY onEnableChanged)

public:
  enum class State
  {
    kWait,
    kFail,
    kDone
  };

  using Checker = std::function<bool()>;
  using Task = std::function<void()>;
  using ID = uint32_t;

  explicit TaskItem(QObject* parent = nullptr);
  TaskItem(const TaskItem&) = delete;
  TaskItem& operator=(const TaskItem&) = delete;
  virtual ~TaskItem() = default;

  static TaskItem* Build();// TOOD(MN): Use separate class

  void SetID(const uint32_t id);
  uint32_t GetID();
  QString GetTitle();
  TaskItem* SetTitle(const QString& title);
  QString GetImagePath();
  void SetImagePath(const QString& imagePath);
  bool IsEnabled();
  TaskItem* SetEnable(const bool enable);
  TaskItem* SetTask(const Task task, const Checker checker);
  Q_INVOKABLE void CheckAsync();
  Q_INVOKABLE bool Check();
  Q_INVOKABLE void Run();

signals:
  void titleChanged();
  void imagePathChanged();
  void onEnableChanged();
  void OnIDChanged();
  void OnStateChanged(const unsigned int id, const bool isDone);

private:
  ID id_;
  bool isEnabled_;
  QString title_;
  QString imagePath_;
  Task task_;
  Checker checker_;

  void SetState(const State state);
};

#endif /* TASK_ITEM_H_ */
