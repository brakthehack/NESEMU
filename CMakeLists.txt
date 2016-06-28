cmake_minimum_required(VERSION 3.1)

project(nesemu)

set (CMAKE_CXX_STANDARD 11)

set (NESEMU_VERSION_MAJOR 1)
set (NESEMU_VERSION_MINOR 0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include_directories(${PROJECT_BINARY_DIR}
                    ${PROJECT_SOURCE_DIR}/src/include
                    )

configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_SOURCE_DIR}/src/include/config.h"
  )

add_subdirectory(src)
add_subdirectory(test)

enable_testing()

add_test(NAME InstructionTest COMMAND unit-test)
