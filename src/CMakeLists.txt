#set(HEADERS ???)
set(SOURCES main.cpp)
set(APP ${PROJECT_NAME})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(${APP} ${HEADERS} ${SOURCES})

target_link_libraries(${APP}
    PRIVATE Qt5::Core Qt5::Quick
)
