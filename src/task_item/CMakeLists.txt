# Headers
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(PRIVATE_INCLUDE_DIRS "")
set(HEADERS
    ${PUBLIC_INCLUDE_DIRS}/task_item/task_item.h
    ${PUBLIC_INCLUDE_DIRS}/task_item/task_container_interface.h
    ${PUBLIC_INCLUDE_DIRS}/task_item/task_container.h
)

# Sources
set(SOURCES task_item.cc task_container.cc)

# Libraries
set(PRIVATE_LIBRARIES "")
set(PUBLIC_LIBRARIES Qt5::Core Qt5::Quick)

# Packages
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# Project
set(LIB task_item)
add_library(${LIB} STATIC
    ${HEADERS}
    ${SOURCES}
)

# Linking
target_include_directories(${LIB}
    PUBLIC  ${PUBLIC_INCLUDE_DIRS}
    PRIVATE ${PRIVATE_INCLUDE_DIRS}
)
target_link_libraries(${LIB}
    PUBLIC  ${PUBLIC_LIBRARIES}
    PRIVATE ${PRIVATE_LIBRARIES}
)
