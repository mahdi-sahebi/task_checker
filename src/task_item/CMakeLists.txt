set(PRIVATE_HEADERS ${PROJECT_SOURCE_DIR}/include/task_item)
set(HEADERS ${PRIVATE_HEADERS}/task_item.h)
set(SOURCES task_item.cpp)
set(LIB_NAME task_item)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${LIB_NAME}
    PRIVATE ${PRIVATE_HEADERS}
)

target_link_libraries(${LIB_NAME}
    PUBLIC Qt5::Core Qt5::Quick
)
