cmake_minimum_required( VERSION 3.13 )

#set(GCC_LOCATION "/tools/gcc/redhat/8/10.1.0/")
#set(CMAKE_C_COMPILER "/tools/gcc/redhat/8/10.1.0/bin/gcc")
#set(CMAKE_CXX_COMPILER "/tools/gcc/redhat/8/10.1.0/bin/g++")
#set(CONAN_DISABLE_CHECK_COMPILER ON)

#set(ENV{PATH} "${GCC_LOCATION}/bin:$ENV{PATH}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(uring_reactor VERSION 0.0.1 LANGUAGES CXX )

include(conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP CMAKE_TARGETS UPDATE
                PROFILE ${CMAKE_SOURCE_DIR}/conan_profile
                BUILD missing)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

add_library(uring_reactor STATIC
        uringio/uring_reactor.cpp
        uringio/work.cpp)
target_include_directories(uring_reactor PUBLIC include)

add_executable(run_loop examples/run_loop.cpp)
target_link_libraries(run_loop PUBLIC uring_reactor)
