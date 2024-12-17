# Headers
set(PRIVATE_INCLUDE_DIRS "")
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS
    ${PUBLIC_INCLUDE_DIRS}/page/page_container.h
    ${PUBLIC_INCLUDE_DIRS}/page/page.h
)

# Sources
set(SOURCES page_container.cc page.cc)

# Libraries
set(PRIVATE_LIBRARIES "")
set(PUBLIC_LIBRARIES task_item)

# Pacakges

# Project
set(LIB page)
add_library(${LIB} STATIC ${SOURCES} ${HEADERS})

# Linking
target_include_directories(${LIB}
    PRIVATE ${PRIVATE_INCLUDE_DIRS}
    PUBLIC  ${PUBLIC_INCLUDE_DIRS}
)
target_link_libraries(${LIB}
    PRIVATE ${PRIVATE_LIBRARIES}
    PUBLIC ${PUBLIC_LIBRARIES}
)
