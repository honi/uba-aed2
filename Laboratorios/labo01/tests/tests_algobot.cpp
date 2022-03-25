#include "gtest-1.8.1/gtest.h"
#include "algobot.h"

using namespace std;

TEST(LU, Constructor) {
    LU lu1("123/45");
    EXPECT_EQ(lu1.numero(), 123);
    EXPECT_EQ(lu1.anio(), 45);

    LU lu2("008/09");
    EXPECT_EQ(lu2.numero(), 8);
    EXPECT_EQ(lu2.anio(), 9);

    LU lu3("123/45;");
    EXPECT_EQ(lu1.numero(), 123);
    EXPECT_EQ(lu1.anio(), 45);
}

TEST(Mail, libretas) {
    Mail m1("123/45", 0, false);
    EXPECT_EQ(set<LU>{LU("123/45")}, m1.libretas());

    Mail m2("123/45;009/08", 0, false);
    EXPECT_EQ(set<LU>({LU("123/45"), LU("009/08")}), m2.libretas());

    Mail m3("123/45;009/08;", 0, false);
    EXPECT_EQ(set<LU>({LU("123/45"), LU("009/08")}), m3.libretas());

    Mail m4("009/08;123/45", 0, false);
    EXPECT_EQ(set<LU>({LU("123/45"), LU("009/08")}), m4.libretas());
}
