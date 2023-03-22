cmake_minimum_required(VERSION 3.15)
project(Project)

add_subdirectory(thirdparty)
add_subdirectory(src)

option(BUILD_TESTS "" OFF)

if (BUILD_TESTS)
    message("Building tests...")
    add_subdirectory(tests)
endif()

option(BUILD_EXAMPLE "" OFF)

if (BUILD_EXAMPLE)
    message("Building example...")
    add_subdirectory(example)
endif()