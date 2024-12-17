#include <thread>
#include <chrono>
#include "application/application.h"


using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


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

    static bool result_1 = false;
    page_1->AddTask(
        100,
        "Task description 100",
        []() {
            sleep_for(milliseconds(1000));
            result_1 = !result_1;
        },
        []() {
            sleep_for(milliseconds(1950));
            return result_1;
        });

    static bool result_2 = false;
    page_1->AddTask(
        101,
        "Task description 101",
        []() {
            sleep_for(milliseconds(4100));
            result_2 = !result_2;
        },
        []() {
            sleep_for(milliseconds(3300));
            return result_2;
        });

    static bool result_3 = false;
    page_1->AddTask(
        102,
        "Task description 102",
        []() {
            sleep_for(milliseconds(100));
            result_3 = !result_3;
        },
        []() {
            sleep_for(milliseconds(675));
            return result_3;
        });

    static bool result_4 = false;
    page_1->AddTask(
        103,
        "Task description 104",
        []() {
            sleep_for(milliseconds(400));
            result_4 = !result_4;
        },
        []() {
            sleep_for(milliseconds(2675));
            return result_4;
        });

    static bool result_5 = false;
    page_1->AddTask(
        104,
        "Task description 105",
        []() {
            sleep_for(milliseconds(60));
            result_5 = !result_5;
        },
        []() {
            sleep_for(milliseconds(75));
            return result_5;
        });

    static bool result_6 = false;
    page_1->AddTask(
        105,
        "Task description 106",
        []() {
            sleep_for(milliseconds(2060));
            result_6 = !result_6;
        },
        []() {
            sleep_for(milliseconds(2075));
            return result_6;
        });

    static bool result_7 = false;
    page_1->AddTask(
        106,
        "Task description 107",
        []() {
            sleep_for(milliseconds(1060));
            result_7 = !result_7;
        },
        []() {
            sleep_for(milliseconds(1075));
            return result_7;
        });
}

void AppInitiator::createPage2()
{
    auto page_2 = page_container_.Add(1, "Page 2");
    page_2->ClearTasks();

    static bool result_1 = false;
    page_2->AddTask(
        200,
        "Task description 200",
        []() {
            sleep_for(milliseconds(1000));
            result_1 = !result_1;
        },
        []() {
            sleep_for(milliseconds(350));
            return result_1;
        });
}

void AppInitiator::createPage3()
{
    auto page_3 = page_container_.Add(3, "Page 3");
    (void)page_3;
}
