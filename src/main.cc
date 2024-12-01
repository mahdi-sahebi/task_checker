#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "task_item/task_item.h"
#include "task_item/task_container.h"
#include "page/page.h"
#include "page/page_container.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // TODO(MN): ELB namespace for all modules
    qmlRegisterType<TaskItem>("Task.Item", 1, 0, "TaskItem");
    qmlRegisterType<TaskContainer>("Task.Container", 1, 0, "TaskContainer");
    qmlRegisterType<Page>("Page.Page", 1, 0, "Page");

    QQmlApplicationEngine engine;
    auto page_container = new PageContainer();
    engine.rootContext()->setContextProperty("page_container", page_container);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    page_container->Add(0, "Page 1");

    return app.exec();
}
