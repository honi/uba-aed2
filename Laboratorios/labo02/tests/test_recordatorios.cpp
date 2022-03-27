#include "gtest-1.8.1/gtest.h"
#include "../src/Recordatorios.cpp"
#include <sstream>

using namespace std;

#if EJ >= 7

TEST(Fecha, init) {
  Fecha f(6, 10);
  EXPECT_EQ(f.mes(), 6);
  EXPECT_EQ(f.dia(), 10);
}

#endif

#if EJ >= 8

TEST(Fecha, ostream) {
  stringstream ss;
  Fecha f(6, 10);
  ss << f;
  EXPECT_EQ(ss.str(), "10/6");
}

#endif

#if EJ >= 9 

TEST(Fecha, igualdad) {
  Fecha f(6, 10);
  Fecha f2(6, 10);
  Fecha f3(7, 10);
  Fecha f4(6, 11);
  EXPECT_TRUE(f == f2);
  EXPECT_FALSE(f == f3);
  EXPECT_FALSE(f == f4);
}

#endif

#if EJ >= 10

TEST(Fecha, incrementar) {
  Fecha f(6, 28);
  EXPECT_EQ(f.mes(), 6);
  EXPECT_EQ(f.dia(), 28);

  f.incrementar_dia();
  EXPECT_EQ(f.mes(), 6);
  EXPECT_EQ(f.dia(), 29);

  f.incrementar_dia();
  EXPECT_EQ(f.mes(), 6);
  EXPECT_EQ(f.dia(), 30);
  
  f.incrementar_dia();
  EXPECT_EQ(f.mes(), 7);
  EXPECT_EQ(f.dia(), 1);

  f = Fecha(2, 28);
  EXPECT_EQ(f.mes(), 2);
  EXPECT_EQ(f.dia(), 28);

  f.incrementar_dia();
  EXPECT_EQ(f.mes(), 3);
  EXPECT_EQ(f.dia(), 1);
}

#endif

#if EJ >= 11

TEST(Horario, init) {
  Horario h(10, 30);
  EXPECT_EQ(h.hora(), 10);
  EXPECT_EQ(h.min(), 30);
}

TEST(Horario, ostream) {
  stringstream ss;
  Horario h(10, 30);
  ss << h;
  EXPECT_EQ(ss.str(), "10:30");
}

#endif

#if EJ >= 12

TEST(Horario, comparacion) {
  Horario h(10, 30);
  Horario h2(10, 31);
  EXPECT_TRUE(h < h2);
  EXPECT_FALSE(h2 < h);
}

#endif

#if EJ >= 13

TEST(Recordatorio, ostream) {
  stringstream ss;
  Recordatorio r(Fecha(6, 10), Horario(9, 45), "Cumple March");
  ss << r; // Cumple March @ 10/6 9:45
  EXPECT_EQ(ss.str(), "Cumple March @ 10/6 9:45");
}

#endif

#if EJ >= 14
TEST(Agenda, ordenado) {
  Agenda a(Fecha(5, 10));
  a.agregar_recordatorio(Recordatorio(Fecha(5, 10), Horario(9, 0), "Clase Algo2"));
  a.agregar_recordatorio(Recordatorio(Fecha(5, 10), Horario(11, 0), "Labo Algo2"));

  stringstream ss;
  ss << a;
  stringstream ss2;
  ss2 << "10/5" << endl;
  ss2 << "=====" << endl;
  ss2 << "Clase Algo2 @ 10/5 9:0" << endl;
  ss2 << "Labo Algo2 @ 10/5 11:0" << endl;
  EXPECT_EQ(ss.str(), ss2.str());
}

TEST(Agenda, desordenado) {
  Agenda a(Fecha(5, 10));
  a.agregar_recordatorio(Recordatorio(Fecha(5, 10), Horario(11, 0), "Labo Algo2"));
  a.agregar_recordatorio(Recordatorio(Fecha(5, 10), Horario(9, 0), "Clase Algo2"));

  stringstream ss;
  ss << a;
  stringstream ss2;
  ss2 << "10/5" << endl;
  ss2 << "=====" << endl;
  ss2 << "Clase Algo2 @ 10/5 9:0" << endl;
  ss2 << "Labo Algo2 @ 10/5 11:0" << endl;
  EXPECT_EQ(ss.str(), ss2.str());
}

TEST(Agenda, cambio_dia) {
  Agenda a(Fecha(5, 9));
  a.agregar_recordatorio(Recordatorio(Fecha(5, 10), Horario(11, 0), "Labo Algo2"));
  a.agregar_recordatorio(Recordatorio(Fecha(5, 10), Horario(9, 0), "Clase Algo2"));

  stringstream ss1;
  ss1 << a;
  stringstream ss1c;
  ss1c << "9/5" << endl;
  ss1c << "=====" << endl;
  EXPECT_EQ(ss1c.str(), ss1.str());

  a.incrementar_dia();
  stringstream ss2;
  ss2 << a;

  stringstream ss2c;
  ss2c << "10/5" << endl;
  ss2c << "=====" << endl;
  ss2c << "Clase Algo2 @ 10/5 9:0" << endl;
  ss2c << "Labo Algo2 @ 10/5 11:0" << endl;
  EXPECT_EQ(ss2.str(), ss2c.str());
}
#endif
