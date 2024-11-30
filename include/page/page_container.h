#ifndef PAGE_CONTAINER_H_
#define PAGE_CONTAINER_H_

#include <cstdint>
#include <QObject>
#include <QString>
#include <QVariantList>

class PageContainer : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QVariantList list READ GetList NOTIFY OnListChanged)

public:
    PageContainer();
    PageContainer(const PageContainer&) = delete;
    PageContainer& operator=(const PageContainer&) = delete;
    virtual ~PageContainer();

    Q_INVOKABLE bool Add(const uint16_t id, const QString& title);
    Q_INVOKABLE bool Remove(const uint16_t id);
    Q_INVOKABLE void Clear();
    QVariantList GetList();

signals:
    void OnListChanged();

private:
    QVariantList list_;
};

#endif /* PAGE_CONTAINER_H_ */
