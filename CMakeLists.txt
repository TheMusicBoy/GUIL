cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_CXX_STANDARD 17)

# Thread configs
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

add_subdirectory(thirdparty)
add_subdirectory(src)

option(BUILD_TESTS "" OFF)

if (BUILD_TESTS)
    message("Building tests...")
    add_subdirectory(tests)
endif()

option(BUILD_EXAMPLES "" OFF)

if (BUILD_EXAMPLES)
    message("Building example...")
    add_subdirectory(example)
endif()