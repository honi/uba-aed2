cmake_minimum_required(VERSION 3.5)
project(solucion)

set(CMAKE_CXX_STANDARD 11)

# Algunos flags para pasar al compilador (gnu++11 en vez de c++11 para que sea cross-plat)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

# Leemos todos los archivos fuentes en ./src
# file(GLOB SOURCE_FILES src/*.cpp src/*.h)

add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

# Creamos el ejecutable para correr los tests
foreach(i RANGE 1 6)
    add_executable(ej${i} tests/test_geometria.cpp)
endforeach(i)
foreach(i RANGE 7 14)
    add_executable(ej${i} tests/test_recordatorios.cpp)
endforeach(i)
add_executable(ej15 tests/test_juego.cpp)
add_executable(truco tests/test_truco.cpp)
add_executable(libreta tests/test_libreta.cpp)

# Definiciones por target
foreach(i RANGE 1 14)
    target_compile_definitions(ej${i} PUBLIC EJ=${i})
endforeach(i)

# Necesitamos asociar los archivos del framework de testing
foreach(i RANGE 1 14)
    target_link_libraries(ej${i} gtest gtest_main)
endforeach(i)
target_link_libraries(ej15 gtest gtest_main)
target_link_libraries(truco gtest gtest_main)
target_link_libraries(libreta gtest gtest_main)
