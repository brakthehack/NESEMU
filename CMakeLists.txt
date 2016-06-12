cmake_minimum_required(VERSION 3.1)

# Project's name

project(nesemu)

set (CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include")

set (NESEMU_VERSION_MAJOR 1)
set (NESEMU_VERSION_MINOR 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_SOURCE_DIR}/include/config.h"
  )


file(GLOB CPU_SRC
    "${PROJECT_SOURCE_DIR}/cpu/*.cpp"
    "${PROJECT_SOURCE_DIR}/mmu/*.cpp"
    "${PROJECT_SOURCE_DIR}/cpu/addressmode/*.cpp"
)

add_executable(nesemu main.cpp ${CPU_SRC} )
