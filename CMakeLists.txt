cmake_minimum_required(VERSION 2.8)

project(strings_h)

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.c)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
