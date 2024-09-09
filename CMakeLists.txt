cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(task_checker LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD  17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(src)

set(QML_IMPORT_PATH ${CMAKE_SROUCE_DIR}/qml)
qt5_add_resources(QML_RESOURCES qml/qml.qrc)
