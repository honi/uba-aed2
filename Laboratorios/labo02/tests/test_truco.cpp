#include "gtest-1.8.1/gtest.h"
#include "../src/Truco.cpp"
#include <sstream>

using namespace std;

TEST(truco, init) {
  Truco t;
  EXPECT_EQ(t.puntaje_j1(), 0);
  EXPECT_EQ(t.puntaje_j2(), 0);
}

TEST(truco, sumar) {
  Truco t;
  EXPECT_EQ(t.puntaje_j1(), 0);
  EXPECT_EQ(t.puntaje_j2(), 0);
  t.sumar_punto(1);
  EXPECT_EQ(t.puntaje_j1(), 1);
  EXPECT_EQ(t.puntaje_j2(), 0);
  t.sumar_punto(1);
  EXPECT_EQ(t.puntaje_j1(), 2);
  EXPECT_EQ(t.puntaje_j2(), 0);

  t.sumar_punto(2);
  EXPECT_EQ(t.puntaje_j1(), 2);
  EXPECT_EQ(t.puntaje_j2(), 1);
  
  t.sumar_punto(2);
  EXPECT_EQ(t.puntaje_j1(), 2);
  EXPECT_EQ(t.puntaje_j2(), 2);
}

TEST(truco, buenas) {
  Truco t;
  for (uint i = 0; i < 15; i++) {
    t.sumar_punto(1);
  }
  EXPECT_EQ(t.puntaje_j1(), 15);
  EXPECT_FALSE(t.buenas(1));

  t.sumar_punto(1);
  EXPECT_EQ(t.puntaje_j1(), 16);
  EXPECT_TRUE(t.buenas(1));
  
  t.sumar_punto(1);
  EXPECT_EQ(t.puntaje_j1(), 17);
  EXPECT_TRUE(t.buenas(1));
}

TEST(truco, imprimir) {
  stringstream ss;
  Truco t;
  for (uint i = 0; i < 4; i++) {
    t.sumar_punto(1);
  }
  for (uint i = 0; i < 12; i++) {
    t.sumar_punto(2);
  }
  ss << t;
  EXPECT_EQ(ss.str(), "J1: 4 | J2: 12");
}

TEST(truco, igualdad) {
  Truco t, t2;
  EXPECT_TRUE(t == t2);
  t.sumar_punto(1);
  EXPECT_FALSE(t == t2);
  t2.sumar_punto(1);
  EXPECT_TRUE(t == t2);
  t.sumar_punto(2);
  EXPECT_FALSE(t == t2);
  t2.sumar_punto(2);
  EXPECT_TRUE(t == t2);
}
