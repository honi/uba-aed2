#include "gtest-1.8.1/gtest.h"
#include "../src/Juego.cpp"

TEST(Juego, init) {
  Juego j(10, make_pair(0, 0));
  EXPECT_EQ(j.turno_actual(), 0);
  EXPECT_EQ(j.posicion_jugador(), make_pair(0, 0));
}

TEST(Juego, sin_pocion) {
  Juego j(10, make_pair(0, 0));

  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(0, 1));
  EXPECT_EQ(j.turno_actual(), 1);

  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(0, 2));
  EXPECT_EQ(j.turno_actual(), 2);
  
  j.mover_jugador(ABAJO);
  EXPECT_EQ(j.posicion_jugador(), make_pair(1, 2));
  EXPECT_EQ(j.turno_actual(), 3);
  
  j.mover_jugador(IZQUIERDA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(1, 1));
  EXPECT_EQ(j.turno_actual(), 4);
  
  j.mover_jugador(ARRIBA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(0, 1));
  EXPECT_EQ(j.turno_actual(), 5);
}

TEST(Juego, con_una_pocion) {
  Juego j(10, make_pair(2, 2));
  j.ingerir_pocion(2, 10);

  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 3));
  EXPECT_EQ(j.turno_actual(), 0);
  
  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 4));
  EXPECT_EQ(j.turno_actual(), 1);
  
  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 5));
  EXPECT_EQ(j.turno_actual(), 1);
  
  j.mover_jugador(ABAJO);
  EXPECT_EQ(j.posicion_jugador(), make_pair(3, 5));
  EXPECT_EQ(j.turno_actual(), 2);
  
  j.mover_jugador(ABAJO);
  EXPECT_EQ(j.posicion_jugador(), make_pair(4, 5));
  EXPECT_EQ(j.turno_actual(), 2);
}

TEST(Juego, con_dos_pociones) {
  Juego j(10, make_pair(2, 2));
  j.ingerir_pocion(1, 10);
  j.ingerir_pocion(1, 5);

  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 3));
  EXPECT_EQ(j.turno_actual(), 0);
  
  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 4));
  EXPECT_EQ(j.turno_actual(), 1);
  
  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 5));
  EXPECT_EQ(j.turno_actual(), 1);
  
  j.mover_jugador(ABAJO);
  EXPECT_EQ(j.posicion_jugador(), make_pair(3, 5));
  EXPECT_EQ(j.turno_actual(), 2);
  
  j.mover_jugador(ABAJO);
  EXPECT_EQ(j.posicion_jugador(), make_pair(4, 5));
  EXPECT_EQ(j.turno_actual(), 2);
}

TEST(Juego, fin_una_pocion) {
  Juego j(10, make_pair(2, 2));
  j.ingerir_pocion(2, 2);

  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 3));
  EXPECT_EQ(j.turno_actual(), 0);
  
  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 4));
  EXPECT_EQ(j.turno_actual(), 1);
  
  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.posicion_jugador(), make_pair(2, 5));
  EXPECT_EQ(j.turno_actual(), 1);
  
  j.mover_jugador(ABAJO);
  EXPECT_EQ(j.posicion_jugador(), make_pair(3, 5));
  EXPECT_EQ(j.turno_actual(), 2);
  
  j.mover_jugador(ABAJO);
  EXPECT_EQ(j.posicion_jugador(), make_pair(4, 5));
  EXPECT_EQ(j.turno_actual(), 3);
  
  j.mover_jugador(ABAJO);
  EXPECT_EQ(j.turno_actual(), 4);
}

TEST(Juego, fin_dos_pociones) {
  Juego j(10, make_pair(2, 2));
  j.ingerir_pocion(2, 2);
  j.ingerir_pocion(1, 1);

  EXPECT_EQ(j.turno_actual(), 0);

  j.mover_jugador(DERECHA);
  j.mover_jugador(IZQUIERDA);
  EXPECT_EQ(j.turno_actual(), 0);

  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.turno_actual(), 1);
  
  j.mover_jugador(IZQUIERDA);
  EXPECT_EQ(j.turno_actual(), 1);

  j.mover_jugador(DERECHA);
  EXPECT_EQ(j.turno_actual(), 2);

  j.mover_jugador(IZQUIERDA);
  EXPECT_EQ(j.turno_actual(), 3);
}
