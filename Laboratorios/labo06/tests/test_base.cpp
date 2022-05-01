#include "gtest/gtest.h"
#include "../src/Templates.cpp"
#include <string>

using namespace std;

TEST(Base, cuadrado) {
  EXPECT_EQ(cuadrado(5), 25);
  EXPECT_EQ(cuadrado(10), 100);
  EXPECT_EQ(cuadrado(1), 1);
}

TEST(Base, contiene) {
  EXPECT_TRUE(contiene(string("Hola todos"), 't'));
  EXPECT_TRUE(contiene(string("Hola todos"), 'H'));
  EXPECT_TRUE(contiene(string("Hola todos"), ' '));
  EXPECT_FALSE(contiene(string("Hola todos"), 'h'));
}
