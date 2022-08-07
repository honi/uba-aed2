#include "gtest-1.8.1/gtest.h"
#include "../src/aed2_Servidor.h"

class ServidorTest : public testing::Test {
protected:
    Casilla pos0, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9;
    set<Casilla> posicion1, posicion2, posiciones234, posiciones01234, posiciones56789;
    set<int> h1, v1, h2, v2, h3, v3, h4, v4, h12, v12, h1234, v1234;
    Jugador jugador1, jugador2, jugador3, jugador4;

    void SetUp() {
        pos0 = {-2, -2};
        pos1 = {4, -2};
        pos2 = {3, 0};
        pos3 = {5, -3};
        pos4 = {4, -3};
        pos5 = {2, 0};
        pos6 = {2, -4};
        pos7 = {6, 0};
        pos8 = {6, -4};
        pos9 = {4, 7};
        posicion1 = {pos1};
        posicion2 = {pos2};
        posiciones234 = {pos2, pos3, pos4};
        posiciones01234 = {pos0, pos1, pos2, pos3, pos4};
        posiciones56789 = {pos5, pos6, pos7, pos8, pos9};
        jugador1 = "jugador1";
        jugador2 = "jugador2";
        jugador3 = "jugador3";
        jugador4 = "jugador4";
        h1 = {1, 5, -6, -1};
        v1 = {0, 7, -3};
        h2 = {1, 3, -5};
        v2 = {-8, 1, -3};
        h3 = {-6, -9, 9};
        v3 = {9, -5, -8};
        h4 = {6, -7, 8};
        v4 = {-3, 8, -5};
        h12 = {-1, 1, 3, 5, -5, -6};
        v12 = {0, 1, -3, 7, -8};
        h1234 = {-9, -7, -6, -5, -1, 9, 8, 6, 5, 3, 1};
        v1234 = {-8, 9, -5, 8, -3, 7, 0, 1};
    }
};

TEST_F(ServidorTest, empezar_partida) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 0);
    EXPECT_TRUE(s.casas(jugador1).empty());
    EXPECT_TRUE(s.comercios(jugador1).empty());
}

TEST_F(ServidorTest, agregar_casa) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarCasa(jugador1, pos1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 0);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_EQ(s.casas(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 0);
}

TEST_F(ServidorTest, agregar_comercio) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarComercio(jugador1, pos1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 0);
    EXPECT_TRUE(s.casas(jugador1).empty());
    EXPECT_EQ(s.comercios(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 0);
}

TEST_F(ServidorTest, avanzar_turno) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarCasa(jugador1, pos1);
    s.avanzarTurno(jugador1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 1);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_EQ(s.casas(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 1);
}

TEST_F(ServidorTest, agregar_multiples_casas) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarCasa(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos4);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 2);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_EQ(s.casas(jugador1), posiciones234);
    EXPECT_EQ(s.nivel(jugador1, pos2), 2);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 0);
}

TEST_F(ServidorTest, agregar_multiples_comercios) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarComercio(jugador1, pos4);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos2);
    s.avanzarTurno(jugador1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 3);
    EXPECT_TRUE(s.casas(jugador1).empty());
    EXPECT_EQ(s.comercios(jugador1), posiciones234);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 2);
    EXPECT_EQ(s.nivel(jugador1, pos4), 3);
}

TEST_F(ServidorTest, comercio_con_casa_mejor_cercana) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarCasa(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posicion1);
    EXPECT_EQ(s.comercios(jugador1), posicion2);
    EXPECT_EQ(s.nivel(jugador1, pos1), 1);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
}

TEST_F(ServidorTest, comercio_con_casa_peor_cercana) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarComercio(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posicion1);
    EXPECT_EQ(s.comercios(jugador1), posicion2);
    EXPECT_EQ(s.nivel(jugador1, pos1), 0);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
}

TEST_F(ServidorTest, comercio_con_varias_casas_cercanas) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos4);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 4);
    EXPECT_EQ(s.casas(jugador1), posiciones234);
    EXPECT_EQ(s.comercios(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 4);
    EXPECT_EQ(s.nivel(jugador1, pos2), 2);
    EXPECT_EQ(s.nivel(jugador1, pos3), 4);
    EXPECT_EQ(s.nivel(jugador1, pos4), 3);
}

TEST_F(ServidorTest, comercio_con_casas_lejanas) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarCasa(jugador1, pos5);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos6);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos7);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos8);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos9);
    s.agregarComercio(jugador1, pos1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 4);
    EXPECT_EQ(s.casas(jugador1), posiciones56789);
    EXPECT_EQ(s.comercios(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 0);
    EXPECT_EQ(s.nivel(jugador1, pos5), 4);
    EXPECT_EQ(s.nivel(jugador1, pos6), 3);
    EXPECT_EQ(s.nivel(jugador1, pos7), 2);
    EXPECT_EQ(s.nivel(jugador1, pos8), 1);
    EXPECT_EQ(s.nivel(jugador1, pos9), 0);
}

TEST_F(ServidorTest, varias_construcciones_en_mismo_turno) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.agregarCasa(jugador1, pos0);
    s.agregarComercio(jugador1, pos9);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos1);
    s.agregarComercio(jugador1, pos7);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos6);
    s.agregarCasa(jugador1, pos2);
    s.agregarComercio(jugador1, pos8);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos4);
    s.agregarComercio(jugador1, pos5);
    s.avanzarTurno(jugador1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1);
    EXPECT_EQ(s.riosVerticales(jugador1), v1);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 0);
    EXPECT_EQ(s.antiguedad(jugador1), 4);
    EXPECT_EQ(s.casas(jugador1), posiciones01234);
    EXPECT_EQ(s.comercios(jugador1), posiciones56789);
    EXPECT_EQ(s.nivel(jugador1, pos0), 4);
    EXPECT_EQ(s.nivel(jugador1, pos1), 3);
    EXPECT_EQ(s.nivel(jugador1, pos2), 2);
    EXPECT_EQ(s.nivel(jugador1, pos3), 3);
    EXPECT_EQ(s.nivel(jugador1, pos4), 1);
    EXPECT_EQ(s.nivel(jugador1, pos5), 2);
    EXPECT_EQ(s.nivel(jugador1, pos6), 2);
    EXPECT_EQ(s.nivel(jugador1, pos7), 3);
    EXPECT_EQ(s.nivel(jugador1, pos8), 3);
    EXPECT_EQ(s.nivel(jugador1, pos9), 4);
}

TEST_F(ServidorTest, unir_partidas_vacias) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.antiguedad(jugador1), 0);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_TRUE(s.casas(jugador1).empty());
}

TEST_F(ServidorTest, unir_partida_mas_nueva_con_casas) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarCasa(jugador1, pos3);
    s.agregarCasa(jugador1, pos4);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador2, pos2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 1);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_EQ(s.casas(jugador1), posiciones234);
    EXPECT_EQ(s.nivel(jugador1, pos2), 0);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 1);
}

TEST_F(ServidorTest, unir_partida_mas_vieja_con_casas) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarCasa(jugador1, pos3);
    s.agregarCasa(jugador1, pos4);
    s.agregarCasa(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 1);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_EQ(s.casas(jugador1), posiciones234);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 0);
    EXPECT_EQ(s.nivel(jugador1, pos4), 0);
}

TEST_F(ServidorTest, unir_partidas_con_comercios) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos3);
    s.agregarComercio(jugador1, pos4);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador2, pos2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 1);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.casas(jugador1).empty());
    EXPECT_EQ(s.comercios(jugador1), posiciones234);
    EXPECT_EQ(s.nivel(jugador1, pos2), 0);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 1);
}

TEST_F(ServidorTest, unir_casas_solapadas_mismo_nivel) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarCasa(jugador1, pos0);
    s.agregarCasa(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarCasa(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 3);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_EQ(s.casas(jugador1), posiciones01234);
    EXPECT_EQ(s.nivel(jugador1, pos0), 3);
    EXPECT_EQ(s.nivel(jugador1, pos1), 3);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 2);
    EXPECT_EQ(s.nivel(jugador1, pos4), 2);
}

TEST_F(ServidorTest, unir_casas_solapadas_mayor_nivel) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarCasa(jugador1, pos0);
    s.agregarCasa(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarCasa(jugador2, pos2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 3);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_EQ(s.casas(jugador1), posiciones01234);
    EXPECT_EQ(s.nivel(jugador1, pos0), 3);
    EXPECT_EQ(s.nivel(jugador1, pos1), 3);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 2);
    EXPECT_EQ(s.nivel(jugador1, pos4), 1);
}

TEST_F(ServidorTest, unir_casas_solapadas_menor_nivel) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarCasa(jugador1, pos0);
    s.agregarCasa(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos2);
    s.agregarCasa(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarCasa(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 2);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_EQ(s.casas(jugador1), posiciones01234);
    EXPECT_EQ(s.nivel(jugador1, pos0), 2);
    EXPECT_EQ(s.nivel(jugador1, pos1), 2);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 2);
}

TEST_F(ServidorTest, unir_comercios_solapados_mismo_nivel) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos0);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 3);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.casas(jugador1).empty());
    EXPECT_EQ(s.comercios(jugador1), posiciones01234);
    EXPECT_EQ(s.nivel(jugador1, pos0), 3);
    EXPECT_EQ(s.nivel(jugador1, pos1), 3);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 2);
    EXPECT_EQ(s.nivel(jugador1, pos4), 2);
}

TEST_F(ServidorTest, unir_comercios_solapados_mayor_nivel) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos0);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 3);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.casas(jugador1).empty());
    EXPECT_EQ(s.comercios(jugador1), posiciones01234);
    EXPECT_EQ(s.nivel(jugador1, pos0), 3);
    EXPECT_EQ(s.nivel(jugador1, pos1), 3);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 2);
    EXPECT_EQ(s.nivel(jugador1, pos4), 1);
}

TEST_F(ServidorTest, unir_comercios_solapados_menor_nivel) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos0);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos2);
    s.agregarComercio(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 2);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_TRUE(s.casas(jugador1).empty());
    EXPECT_EQ(s.comercios(jugador1), posiciones01234);
    EXPECT_EQ(s.nivel(jugador1, pos0), 2);
    EXPECT_EQ(s.nivel(jugador1, pos1), 2);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 2);
}

TEST_F(ServidorTest, unir_solapamiento_casa_mayor_a_comercio) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 3);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posiciones234);
    EXPECT_EQ(s.comercios(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 3);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 2);
    EXPECT_EQ(s.nivel(jugador1, pos4), 1);
}

TEST_F(ServidorTest, unir_solapamiento_casa_menor_a_comercio) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos2);
    s.agregarCasa(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 2);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posiciones234);
    EXPECT_EQ(s.comercios(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 2);
    EXPECT_EQ(s.nivel(jugador1, pos2), 0);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 2);
}

TEST_F(ServidorTest, unir_solapamiento_comercio_mayor_a_casa) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarCasa(jugador2, pos2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 3);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posiciones234);
    EXPECT_EQ(s.comercios(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 3);
    EXPECT_EQ(s.nivel(jugador1, pos2), 0);
    EXPECT_EQ(s.nivel(jugador1, pos3), 2);
    EXPECT_EQ(s.nivel(jugador1, pos4), 1);
}

TEST_F(ServidorTest, unir_solapamiento_comercio_menor_a_casa) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos2);
    s.agregarCasa(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarCasa(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 2);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posiciones234);
    EXPECT_EQ(s.comercios(jugador1), posicion1);
    EXPECT_EQ(s.nivel(jugador1, pos1), 2);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 2);
}

TEST_F(ServidorTest, unir_comercio_aumenta_nivel_por_casas_cercanas) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos2);
    s.agregarComercio(jugador1, pos4);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos3);
    s.agregarCasa(jugador2, pos1);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 1);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posicion1);
    EXPECT_EQ(s.comercios(jugador1), posiciones234);
    EXPECT_EQ(s.nivel(jugador1, pos1), 1);
    EXPECT_EQ(s.nivel(jugador1, pos2), 1);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 1);
}

TEST_F(ServidorTest, unir_por_casas_cercanas_comercio_aumenta_nivel) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos2);
    s.agregarComercio(jugador1, pos4);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador2, pos3);
    s.unir(jugador1, jugador2);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 2);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posicion1);
    EXPECT_EQ(s.comercios(jugador1), posiciones234);
    EXPECT_EQ(s.nivel(jugador1, pos1), 1);
    EXPECT_EQ(s.nivel(jugador1, pos2), 2);
    EXPECT_EQ(s.nivel(jugador1, pos3), 1);
    EXPECT_EQ(s.nivel(jugador1, pos4), 2);
}

TEST_F(ServidorTest, unir_partidas_y_avanzar_turno) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarCasa(jugador1, pos0);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos3);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos1);
    s.agregarCasa(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos4);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos6);
    s.agregarComercio(jugador1, pos8);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador2, pos9);
    s.avanzarTurno(jugador2);
    s.agregarCasa(jugador2, pos1);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos4);
    s.avanzarTurno(jugador2);
    s.agregarCasa(jugador2, pos3);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos5);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos7);
    s.unir(jugador1, jugador2);
    s.avanzarTurno(jugador1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 7);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.casas(jugador1), posiciones01234);
    EXPECT_EQ(s.comercios(jugador1), posiciones56789);
    EXPECT_EQ(s.nivel(jugador1, pos0), 6);
    EXPECT_EQ(s.nivel(jugador1, pos1), 6);
    EXPECT_EQ(s.nivel(jugador1, pos2), 4);
    EXPECT_EQ(s.nivel(jugador1, pos3), 4);
    EXPECT_EQ(s.nivel(jugador1, pos4), 3);
    EXPECT_EQ(s.nivel(jugador1, pos5), 4);
    EXPECT_EQ(s.nivel(jugador1, pos6), 3);
    EXPECT_EQ(s.nivel(jugador1, pos7), 4);
    EXPECT_EQ(s.nivel(jugador1, pos8), 4);
    EXPECT_EQ(s.nivel(jugador1, pos9), 7);
}

TEST_F(ServidorTest, unir_partidas_y_construir) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.agregarComercio(jugador1, pos0);
    s.agregarCasa(jugador1, pos5);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos6);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos4);
    s.agregarCasa(jugador2, pos8);
    s.agregarComercio(jugador2, pos2);
    s.avanzarTurno(jugador2);
    s.unir(jugador1, jugador2);
    s.agregarCasa(jugador1, pos7);
    s.agregarComercio(jugador1, pos1);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos3);
    s.agregarCasa(jugador1, pos9);
    s.avanzarTurno(jugador1);

    EXPECT_EQ(s.riosHorizontales(jugador1), h12);
    EXPECT_EQ(s.riosVerticales(jugador1), v12);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 4);
    EXPECT_EQ(s.popularidad(jugador1), 1);
    EXPECT_EQ(s.comercios(jugador1), posiciones01234);
    EXPECT_EQ(s.casas(jugador1), posiciones56789);
    EXPECT_EQ(s.nivel(jugador1, pos0), 4);
    EXPECT_EQ(s.nivel(jugador1, pos1), 2);
    EXPECT_EQ(s.nivel(jugador1, pos2), 4);
    EXPECT_EQ(s.nivel(jugador1, pos3), 3);
    EXPECT_EQ(s.nivel(jugador1, pos4), 3);
    EXPECT_EQ(s.nivel(jugador1, pos5), 4);
    EXPECT_EQ(s.nivel(jugador1, pos6), 3);
    EXPECT_EQ(s.nivel(jugador1, pos7), 2);
    EXPECT_EQ(s.nivel(jugador1, pos8), 3);
    EXPECT_EQ(s.nivel(jugador1, pos9), 1);
}

TEST_F(ServidorTest, union_multiple_vacia) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.nuevaPartida(jugador3, h3, v3);
    s.nuevaPartida(jugador4, h4, v4);
    s.unir(jugador1, jugador2);
    s.unir(jugador3, jugador4);
    s.unir(jugador1, jugador3);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1234);
    EXPECT_EQ(s.riosVerticales(jugador1), v1234);
    EXPECT_FALSE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 0);
    EXPECT_EQ(s.popularidad(jugador1), 3);
    EXPECT_TRUE(s.comercios(jugador1).empty());
    EXPECT_TRUE(s.casas(jugador1).empty());
}

TEST_F(ServidorTest, union_multiple) {
    aed2_Servidor s;
    s.nuevaPartida(jugador1, h1, v1);
    s.nuevaPartida(jugador2, h2, v2);
    s.nuevaPartida(jugador3, h3, v3);
    s.nuevaPartida(jugador4, h4, v4);
    s.agregarComercio(jugador1, pos0);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador1, pos8);
    s.agregarComercio(jugador1, pos2);
    s.avanzarTurno(jugador1);
    s.agregarCasa(jugador2, pos6);
    s.avanzarTurno(jugador2);
    s.agregarComercio(jugador2, pos5);
    s.agregarComercio(jugador2, pos8);
    s.agregarCasa(jugador4, pos9);
    s.avanzarTurno(jugador4);
    s.agregarCasa(jugador4, pos5);
    s.avanzarTurno(jugador4);
    s.agregarComercio(jugador4, pos8);
    s.avanzarTurno(jugador4);
    s.agregarComercio(jugador4, pos4);
    s.avanzarTurno(jugador4);
    s.unir(jugador1, jugador2);
    s.avanzarTurno(jugador1);
    s.unir(jugador3, jugador4);
    s.agregarComercio(jugador3, pos6);
    s.unir(jugador1, jugador3);
    s.agregarComercio(jugador1, pos1);
    s.agregarCasa(jugador1, pos7);
    s.avanzarTurno(jugador1);
    s.agregarComercio(jugador1, pos3);

    EXPECT_EQ(s.riosHorizontales(jugador1), h1234);
    EXPECT_EQ(s.riosVerticales(jugador1), v1234);
    EXPECT_TRUE(s.huboConstruccion(jugador1));
    EXPECT_EQ(s.antiguedad(jugador1), 5);
    EXPECT_EQ(s.popularidad(jugador1), 3);
    EXPECT_EQ(s.comercios(jugador1), posiciones01234);
    EXPECT_EQ(s.casas(jugador1), posiciones56789);
    EXPECT_EQ(s.nivel(jugador1, pos0), 4);
    EXPECT_EQ(s.nivel(jugador1, pos1), 1);
    EXPECT_EQ(s.nivel(jugador1, pos2), 4);
    EXPECT_EQ(s.nivel(jugador1, pos3), 3);
    EXPECT_EQ(s.nivel(jugador1, pos4), 3);
    EXPECT_EQ(s.nivel(jugador1, pos5), 4);
    EXPECT_EQ(s.nivel(jugador1, pos6), 3);
    EXPECT_EQ(s.nivel(jugador1, pos7), 1);
    EXPECT_EQ(s.nivel(jugador1, pos8), 3);
    EXPECT_EQ(s.nivel(jugador1, pos9), 5);
}
