cmake_minimum_required(VERSION 2.8)

project(Pathfinder)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories ("${PROJECT_SOURCE_DIR}/src")

add_subdirectory(include)
add_subdirectory(src)

