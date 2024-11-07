#ifndef TASK_ITEM_H_
#define TASK_ITEM_H_

#include <cstdbool>
#include <string>
#include <functional>
#include <mutex>
#include <thread>
#include <QObject>
#include <QString>


class TaskItem : public QObject
{
Q_OBJECT
Q_PROPERTY(QString title READ GetTitle WRITE SetTitle NOTIFY OnTitleChanged)
Q_PROPERTY(QString image_path READ GetImagePath WRITE SetImagePath NOTIFY OnImagePathChanged)

public:
  enum class State
  {
    kWait,
    kFail,
    kDone
  };

  using Task = std::function<bool()>;

  explicit TaskItem(std::string title, const Task& task, QObject* parent = nullptr);
  ~TaskItem();

  QString GetTitle();
  void    SetTitle(const QString& title);
  QString GetImagePath();
  void    SetImagePath(const QString& image_path);
  Q_INVOKABLE void Check();

signals:
  void OnTitleChanged();
  void OnImagePathChanged();

private:
  QString title_;
  QString image_path_;
  const Task& task_;
  std::mutex task_mutex_;

  Q_INVOKABLE void SetState(const State state);
};

#endif /* TASK_ITEM_H_ */
