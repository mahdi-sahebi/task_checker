#include <thread>
#include <chrono>
#include "application/application.h"


AppInitiator::AppInitiator(QQmlApplicationEngine& engine)
{
    defineDataTypes();
    defineGlobals(engine);
    initialize();
}

AppInitiator::~AppInitiator()
{
}

void AppInitiator::defineDataTypes()
{
    // TODO(MN): ELB namespace for all modules
    qmlRegisterType<TaskItem>("Task.Item", 1, 0, "TaskItem");
    qmlRegisterType<TaskContainer>("Task.Container", 1, 0, "TaskContainer");
    qmlRegisterType<Page>("Page.Page", 1, 0, "Page");

}

void AppInitiator::defineGlobals(QQmlApplicationEngine& engine)
{
    engine.rootContext()->setContextProperty("page_container", &page_container_);

}

void AppInitiator::initialize()
{
    auto page = page_container_.Add(0, "Page 1");
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


    auto page2 = page_container_.Add(1, "Page 2");
    page2->ClearTasks();
    page2->AddTask(200, "Task description 200", []() {
        static bool f = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        f = !f;
        return f;
    });


    auto page3 = page_container_.Add(3, "Page 3");


    page_container_.Remove(1);
}
