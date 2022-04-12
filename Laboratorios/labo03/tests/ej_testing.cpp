#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    ASSERT_EQ(15 + 7, 22);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    ASSERT_EQ(pow(10, 2), 100);
}

// Ejercicios 6
TEST(Aritmetica, potencia_general) {
    for (int n = -5; n < 5; ++n) {
        ASSERT_EQ(pow(n, 2), n * n);
    }
}

// Ejercicios 7
TEST(Diccionario, obtener) {
    map<int, int> m;
    m[42] = 666;
    ASSERT_EQ(m[42], 666);
}

// Ejercicios 8
TEST(Diccionario, definir) {
    map<int, int> m;
    ASSERT_EQ(m.count(42), 0);
    m[42] = 666;
    ASSERT_EQ(m.count(42), 1);
}

// Ejercicios 9
TEST(Truco, inicio) {
    Truco t;
    ASSERT_EQ(t.puntaje_j1(), 0);
    ASSERT_EQ(t.puntaje_j2(), 0);
}

// Ejercicios 10
TEST(Truco, buenas) {
    Truco t;

    for (int i = 0; i < 30; ++i) {
        ASSERT_EQ(t.buenas(1), i >= 16);
        t.sumar_punto(1);
    }

    // Versión verborrágica
    // ASSERT_FALSE(t.buenas(1));
    // for (int i = 0; i < 15; ++i) {
    //     t.sumar_punto(1);
    // }
    // ASSERT_FALSE(t.buenas(1));
    // t.sumar_punto(1);
    // ASSERT_TRUE(t.buenas(1));
    // t.sumar_punto(1);
    // t.sumar_punto(1);
    // ASSERT_TRUE(t.buenas(1));
}
