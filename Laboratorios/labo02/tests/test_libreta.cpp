#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.cpp"

TEST(Libreta, init) {
  Libreta l("123/02");
  EXPECT_EQ(l.lu(), "123/02");
  EXPECT_EQ(l.practicos_aprobados(), set<Materia>());
  EXPECT_EQ(l.finales_aprobados(), set<Materia>());
}

TEST(Libreta, aprobar_practico) {
  Libreta l("123/02");
  l.aprobar_practico("M1");
  EXPECT_EQ(l.practicos_aprobados(), set<Materia>({"M1"}));
  EXPECT_EQ(l.finales_aprobados(), set<Materia>());
}

TEST(Libreta, aprobar_final) {
  Libreta l("123/02");
  l.aprobar_final("M1", 5);
  EXPECT_EQ(l.practicos_aprobados(), set<Materia>({"M1"}));
  EXPECT_EQ(l.finales_aprobados(), set<Materia>({"M1"}));
  EXPECT_EQ(l.nota_final("M1"), 5);
}
