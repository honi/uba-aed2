cmake_minimum_required(VERSION 3.4)
project(uso_clases)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

include_directories(src/)
include_directories(tests/)

file(GLOB SOURCE_FILES src/algobot.h src/algobot.cpp)

add_executable(tests_algobot tests/tests_algobot.cpp ${SOURCE_FILES})
add_executable(tests_ejercitacion tests/tests_funciones.cpp ${SOURCE_FILES})

add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)
target_link_libraries(tests_algobot gtest gtest_main)
target_link_libraries(tests_ejercitacion gtest gtest_main)
