#include "gtest-1.8.1/gtest.h"

#include "../src/SistemaDeMensajes.h"
#include "../src/Internet.h"

TEST(SistemaDeMensajes, constructor) {
  SistemaDeMensajes sdm;
  ASSERT_FALSE(sdm.registrado(0));
  ASSERT_FALSE(sdm.registrado(1));
  ASSERT_FALSE(sdm.registrado(2));
  ASSERT_FALSE(sdm.registrado(3));
}

TEST(SistemaDeMensajes, destructor) {
  SistemaDeMensajes sdm;
}

TEST(SistemaDeMensajes, registrarJugador) {
  SistemaDeMensajes sdm;
  ASSERT_FALSE(sdm.registrado(0));
  ASSERT_FALSE(sdm.registrado(1));
  sdm.registrarJugador(0, "IP1");
  ASSERT_TRUE(sdm.registrado(0));
  ASSERT_EQ(sdm.ipJugador(0), "IP1");
  ASSERT_FALSE(sdm.registrado(1));
}

TEST(SistemaDeMensajes, enviar_mensaje) {
  Internet::internet().limpiar();

  SistemaDeMensajes sdm;
  sdm.registrarJugador(0, "IP1");
  sdm.enviarMensaje(0, "A");

  ASSERT_EQ(Internet::internet().mensajes(), list<Msg>({{"IP1", "A"}}));
  sdm.enviarMensaje(0, "B");
  ASSERT_EQ(Internet::internet().mensajes(), list<Msg>({{"IP1", "A"}, {"IP1", "B"}}));
}

TEST(SistemaDeMensajes, enviar_mensaje_distintos_jugadores) {
  Internet::internet().limpiar();

  SistemaDeMensajes sdm;
  sdm.registrarJugador(0, "IP1");
  sdm.registrarJugador(3, "IP3");
  sdm.enviarMensaje(0, "A");
  sdm.enviarMensaje(3, "B");
  sdm.enviarMensaje(0, "C");

  ASSERT_EQ(Internet::internet().mensajes(), list<Msg>({
      {"IP1", "A"},
      {"IP3", "B"},
      {"IP1", "C"},
      }));
}


TEST(SistemaDeMensajes, cambiar_ip) {
  SistemaDeMensajes sdm;
  sdm.registrarJugador(0, "IP1");
  ASSERT_TRUE(sdm.registrado(0));
  ASSERT_EQ(sdm.ipJugador(0), "IP1");
  sdm.registrarJugador(0, "IP2");
  ASSERT_EQ(sdm.ipJugador(0), "IP2");
}


TEST(SistemaDeMensajes, mensaje_cambio_ip) {
  Internet::internet().limpiar();

  SistemaDeMensajes sdm;
  sdm.registrarJugador(0, "IP1");
  sdm.registrarJugador(3, "IP3");
  sdm.enviarMensaje(0, "A");
  sdm.enviarMensaje(3, "B");
  sdm.enviarMensaje(0, "C");

  ASSERT_EQ(Internet::internet().mensajes(), list<Msg>({
      {"IP1", "A"},
      {"IP3", "B"},
      {"IP1", "C"},
      }));

  sdm.registrarJugador(0, "IP1.1");
  sdm.enviarMensaje(0, "A");
  sdm.enviarMensaje(3, "B2");
  ASSERT_EQ(Internet::internet().mensajes(), list<Msg>({
      {"IP1", "A"},
      {"IP3", "B"},
      {"IP1", "C"},
      {"IP1.1", "A"},
      {"IP3", "B2"},
      }));
}

TEST(Proxy, basico) {
  Internet::internet().limpiar();

  SistemaDeMensajes sdm;
  sdm.registrarJugador(0, "IP1");
  sdm.registrarJugador(2, "IP2");
  SistemaDeMensajes::Proxy* p0 = sdm.obtenerProxy(0);
  SistemaDeMensajes::Proxy* p2 = sdm.obtenerProxy(2);
  p0->enviarMensaje("p0.1");
  p2->enviarMensaje("p2.1");

  ASSERT_EQ(Internet::internet().mensajes(), list<Msg>({{"IP1", "p0.1"}, {"IP2", "p2.1"}}));
}

TEST(Proxy, cambio_ip) {
  Internet::internet().limpiar();

  SistemaDeMensajes sdm;
  sdm.registrarJugador(0, "IP0");
  sdm.registrarJugador(2, "IP2");
  SistemaDeMensajes::Proxy* p0 = sdm.obtenerProxy(0);
  SistemaDeMensajes::Proxy* p2 = sdm.obtenerProxy(2);
  p0->enviarMensaje("p0.1");
  p2->enviarMensaje("p2.1");

  ASSERT_EQ(Internet::internet().mensajes(), list<Msg>({{"IP0", "p0.1"}, {"IP2", "p2.1"}}));

  sdm.registrarJugador(0, "IP0.1");
  p0->enviarMensaje("p0.2");
  ASSERT_EQ(Internet::internet().mensajes(), list<Msg>({{"IP0", "p0.1"}, {"IP2", "p2.1"}, {"IP0.1", "p0.2"}}));
}
