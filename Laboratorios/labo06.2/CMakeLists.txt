cmake_minimum_required(VERSION 3.5)
project(algo2_labo_clase5)

# Algunos flags para pasar al compilador (gnu++11 en vez de c++11 para que sea cross-plat)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

include_directories(src/)

add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

foreach(ejN RANGE 1 8)
    add_executable(ej${ejN} tests/algo_tests.cpp)
    target_compile_definitions(ej${ejN} PUBLIC EJ=${ejN})
    target_link_libraries(ej${ejN} gtest gtest_main)
endforeach(ejN)
