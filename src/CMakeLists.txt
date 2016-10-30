file(GLOB CPU_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/cpu/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/mmu/*.cpp"
)

add_library(emulator ${CPU_SRC})

add_executable(nesemu main.cpp)
target_link_libraries(nesemu emulator)
