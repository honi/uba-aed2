#include "gtest-1.8.1/gtest.h"
#include "../src/Geometria.cpp"
#include <sstream>

using namespace std;

#if EJ >= 1

TEST(Rectangulo, init) {
  Rectangulo r(10, 20);
  EXPECT_EQ(r.alto(), 10);
  EXPECT_EQ(r.ancho(), 20);
}

TEST(Rectangulo, area) {
  Rectangulo r(10, 20);
  EXPECT_EQ(r.area(), 10 * 20);
}

#endif

#if EJ >= 2

TEST(Elipse, init) {
  Elipse e(10, 20);
  EXPECT_EQ(e.r_a(), 10);
  EXPECT_EQ(e.r_b(), 20);
}

TEST(Elipse, area) {
  Elipse e(10, 20);
  EXPECT_EQ(e.area(), 10 * 20 * 3.14);
}

#endif 

#if EJ >= 3

TEST(Cuadrado, init) {
  Cuadrado c(15);
  EXPECT_EQ(c.lado(), 15);
}

TEST(Cuadrado, area) {
  Cuadrado c(10);
  EXPECT_EQ(c.area(), 100);
}

#endif

#if EJ >= 4

TEST(Circulo, init) {
  Circulo c(15);
  EXPECT_EQ(c.radio(), 15);
}

TEST(Circulo, area) {
  Circulo c(10);
  EXPECT_EQ(c.area(), 100 * 3.14);
}

#endif

#if EJ >= 5

TEST(Rectangulo, ostream) {
  stringstream ss;
  Rectangulo r(10, 20);
  ss << r;
  EXPECT_EQ(ss.str(), "Rect(10, 20)");
}

TEST(Elipse, ostream) {
  stringstream ss;
  Elipse e(10, 20);
  ss << e;
  EXPECT_EQ(ss.str(), "Elipse(10, 20)");
}

#endif

#if EJ >= 6

TEST(Circulo, ostream) {
  stringstream ss;
  Circulo c(10);
  ss << c;
  EXPECT_EQ(ss.str(), "Circ(10)");
}

TEST(Cuadrado, ostream) {
  stringstream ss;
  Cuadrado c(10);
  ss << c;
  EXPECT_EQ(ss.str(), "Cuad(10)");
}

#endif
