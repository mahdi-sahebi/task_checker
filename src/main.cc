#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "task_item/task_item.h"
#include "task_item/task_container.h"
#include "page/page_container.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<TaskItem>("Task.Item", 1, 0, "TaskItem");
    qmlRegisterType<TaskContainer>("Task.Container", 1, 0, "TaskContainer");

    QQmlApplicationEngine engine;
    auto page_container = new PageContainer();
    engine.rootContext()->setContextProperty("page_container", page_container);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
