#include "gtest-1.8.1/gtest.h"

#include "../src/Periodo.h"

TEST(fecha, periodo) {
  Periodo p(1, 2, 3);
  EXPECT_EQ(p.anios(), 1);
  EXPECT_EQ(p.meses(), 2);
  EXPECT_EQ(p.dias(), 3);

  Periodo p2(10, 40, 50);
  EXPECT_EQ(p2.anios(), 10);
  EXPECT_EQ(p2.meses(), 40);
  EXPECT_EQ(p2.dias(), 50);
}
