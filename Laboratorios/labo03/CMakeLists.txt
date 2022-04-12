cmake_minimum_required(VERSION 3.5)
project(solucion)

set(CMAKE_CXX_STANDARD 11)

# Algunos flags para pasar al compilador (gnu++11 en vez de c++11 para que sea cross-plat)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

# Creamos el ejecutable para correr los tests
add_executable(ej1 tests/ej1_periodo.cpp src/Periodo.cpp)
add_executable(ej2 tests/ej2_periodo_y_fecha.cpp
               src/Periodo.cpp)
add_executable(ej3 tests/ej3_funciones.cpp
               src/Funciones.cpp src/Periodo.cpp src/Fecha.cpp)
add_executable(solucion_testing tests/solucion_testing.cpp src/Truco.cpp
    src/Libreta.cpp)
add_executable(ej_testing tests/ej_testing.cpp src/Truco.cpp
    src/Libreta.cpp)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(ej1 gtest gtest_main)
target_link_libraries(ej2 gtest gtest_main)
target_link_libraries(ej3 gtest gtest_main)
target_link_libraries(solucion_testing gtest gtest_main)
target_link_libraries(ej_testing gtest gtest_main)
