set(PUBLIC_HEADERS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS ${PUBLIC_HEADERS}/task_item/task_item.h)
set(SOURCES task_item.cpp)
set(LIB_NAME task_item)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${LIB_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${LIB_NAME}
    PUBLIC Qt5::Core Qt5::Quick
)
