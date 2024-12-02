#ifndef UI_INITIATOR_H_
#define UI_INITIATOR_H_

#include <QQmlApplicationEngine>
#include <QQmlContext>

class QmlInitiator
{
public:
    virtual void defineDataTypes() = 0;
    virtual void defineGlobals(QQmlApplicationEngine& engine) = 0;
};

#endif /* UI_INITIATOR_H_ */
