set(PRIVATE_INCLUDE_DIRS "")
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/page/page.h)
set(SOURCES page.cc)
set(LIB page)

add_library(${LIB} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${LIB}
    PRIVATE ${PRIVATE_INCLUDE_DIRS}
    PUBLIC  ${PUBLIC_INCLUDE_DIRS}
)
