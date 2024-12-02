#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "task_item/task_item.h"
#include "task_item/task_container.h"
#include "page/page.h"
#include "page/page_container.h"

#include <thread>
#include <chrono>

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



    auto page = page_container->Add(0, "Page 1");
    page->ClearTasks();
    page->AddTask(100, "Task description 100", []() {
        static bool f = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        f = !f;
        return f;
    });

    page->AddTask(101, "Task description 101", []() {
        static bool f = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        f = !f;
        return f;
    });

    page->AddTask(102, "Task description 102", []() {
        static bool f = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        f = !f;
        return f;
    });




    auto page2 = page_container->Add(1, "Page 2");
    page2->ClearTasks();
    page2->AddTask(200, "Task description 200", []() {
        static bool f = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        f = !f;
        return f;
    });



    auto page3 = page_container->Add(3, "Page 3");


    return app.exec();
}
