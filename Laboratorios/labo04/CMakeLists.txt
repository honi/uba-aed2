cmake_minimum_required(VERSION 3.5)
project(algo2_labo_clase4)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

set(SOURCE_FILES src/Internet.cpp src/ConexionJugador.cpp)

message("Test:" ${SOURCE_FILES})

# Ejercicios
add_executable(ej1 tests/sdm_tests.cpp src/SistemaDeMensajes.cpp ${SOURCE_FILES})
add_executable(ej3 tests/sdm_tests.cpp src/SistemaDeMensajes.cpp ${SOURCE_FILES})
add_executable(ej4 tests/sdm_tests.cpp src/SistemaDeMensajes.cpp src/Proxy.cpp ${SOURCE_FILES})
add_executable(ej6 tests/sdm_tests.cpp src/SistemaDeMensajes.cpp src/Proxy2.cpp ${SOURCE_FILES})
add_executable(ej7 tests/sdm_tests_bonus.cpp src/SistemaDeMensajes.cpp ${SOURCE_FILES})

# Definiciones por target
target_compile_definitions(ej1 PUBLIC EJ=1)
target_compile_definitions(ej3 PUBLIC EJ=3)
target_compile_definitions(ej4 PUBLIC EJ=4)
target_compile_definitions(ej6 PUBLIC EJ=6)
target_compile_definitions(ej7 PUBLIC EJ=7)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(ej1 gtest gtest_main)
target_link_libraries(ej3 gtest gtest_main)
target_link_libraries(ej4 gtest gtest_main)
target_link_libraries(ej6 gtest gtest_main)
target_link_libraries(ej7 gtest gtest_main)

# Targets para correr valgrind

add_custom_target(ej2_correrValgrind
        valgrind --leak-check=full -v ./ej1 2>&1
        DEPENDS ej1)

add_custom_target(ej3_correrValgrind
        valgrind --leak-check=full -v ./ej3 2>&1
        DEPENDS ej3)

add_custom_target(ej5_correrValgrind
        valgrind --leak-check=full -v ./ej4 2>&1
        DEPENDS ej4)
