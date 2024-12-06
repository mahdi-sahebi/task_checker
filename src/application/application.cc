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
    createPage1();
    createPage2();
    createPage3();
}

void AppInitiator::createPage1()
{
    auto page_1 = page_container_.Add(0, "Page 1");
    page_1->ClearTasks();

    page_1->AddTask(
        100,
        "Task description 100",
        []() {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        },
        []() {
            static bool result = false;
            result = !result;
            return result;
        });

    page_1->AddTask(
        101,
        "Task description 101",
        []() {
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        },
        []() {
            static bool result = false;
            result = !result;
            return result;
        });

    page_1->AddTask(
        102,
        "Task description 102",
        []() {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        },
        []() {
            static bool result = false;
            result = !result;
            return result;
        });
}

void AppInitiator::createPage2()
{
    auto page_2 = page_container_.Add(1, "Page 2");
    page_2->ClearTasks();

    page_2->AddTask(
        200,
        "Task description 200",
        []() {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        },
        []() {
            static bool result = false;
            result = !result;
            return result;
        });
}

void AppInitiator::createPage3()
{
    auto page_3 = page_container_.Add(3, "Page 3");
    (void)page_3;

//    page_container_.Remove(1);// TODO(MN): Get page id, instead of index
}
