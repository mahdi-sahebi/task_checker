#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "task_item/task_item.h"
#include "task_item/task_container.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<TaskItem>("Task.Item", 1, 0, "TaskItem");
    qmlRegisterType<TaskContainer>("Task.Container", 1, 0, "TaskContainer");

    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("task_item", new TaskItem());

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
