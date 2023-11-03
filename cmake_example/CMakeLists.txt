cmake_minimum_required(VERSION 3.13)

project(Demo)

option(BUILD_TESTS "Whether or not to build tests" ON)

add_subdirectory(src)

if (BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()