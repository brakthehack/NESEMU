cmake_minimum_required(VERSION 3.1)

# Project's name

project(nesemu)

set (CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}")

set (NESEMU_VERSION_MAJOR 1)
set (NESEMU_VERSION MINOR 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

file(GLOB CPU_SRC
    "${PROJECT_SOURCE_DIR}/cpu/*.h"
    "${PROJECT_SOURCE_DIR}/cpu/*.cpp"
)

add_executable(nesemu main.cpp ${CPU_SRC} )
