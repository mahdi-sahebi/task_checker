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
    Q_PROPERTY(bool isEnabled READ IsEnabled() WRITE SetEnable NOTIFY enableChanged)

public:
  class Builder;

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
  TaskItem(TaskItem&&);
  TaskItem& operator=(TaskItem&&);
  virtual ~TaskItem() = default;

  uint32_t GetID();
  QString GetTitle();
  void SetTitle(const QString& title);
  QString GetImagePath();
  bool IsEnabled();
  Q_INVOKABLE void CheckAsync();
  Q_INVOKABLE bool Check();
  Q_INVOKABLE void Run();

signals:
  void titleChanged();
  void imagePathChanged();
  void enableChanged();
  void stateChanged(const unsigned int id, const bool isDone);

private:
  ID id_;
  bool isEnabled_;
  QString title_;
  QString imagePath_;
  Task task_;
  Checker checker_;

  void SetState(const State state);
  void SetID(const uint32_t id);
  TaskItem* SetEnable(const bool enable);// TODO(MN): Separate Enable/Disable APIs
  TaskItem* SetTask(const Task task, const Checker checker);
  void SetImagePath(const QString& imagePath);

  friend class Builder;
};


class TaskItem::Builder
{
public:
    Builder() = default;
    Builder& SetID(const ID id) noexcept;
    Builder& SetTask(const Task task, const Checker checker) noexcept;
    Builder& SetTitle(const QString title) noexcept;
    TaskItem* Build();

private:
    ID id_;
    QString title_;
    QString imagePath_;
    Task task_;
    Checker checker_;

};


#endif /* TASK_ITEM_H_ */
