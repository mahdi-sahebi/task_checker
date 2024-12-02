#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "application_interface.h"
#include "page/page.h"
#include "page/page_container.h"


class AppInitiator : public QmlInitiator
{
public:
    AppInitiator(QQmlApplicationEngine& engine);
    ~AppInitiator();

private:
    PageContainer page_container_;

    void defineDataTypes() override;
    void defineGlobals(QQmlApplicationEngine& engine) override;
    void initialize() override;
};


#endif /* APPLICATION_H_ */
