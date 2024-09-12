#ifndef TASK_ITEM_H_
#define TASK_ITEM_H_

#include <QObject>
#include <QString>

class TaskItem : public QObject
{
Q_OBJECT

public:
  explicit TaskItem(QObject* parent = nullptr);
  ~TaskItem();

  QString GetTitle();
  void SetTitle(const QString& title);

signals:
  void OnTitleChanged();

private:
  QString title_;
};

#endif /* TASK_ITEM_H_ */
