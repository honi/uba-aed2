#ifndef MANEJADORDEEVENTOS_H
#define MANEJADORDEEVENTOS_H

#include <SDL2/SDL.h>
#include "InterfazGrafica.h"

enum Estado {
    Inicial, Nombrar, Faltan2, Falta1, Unir, Principal, AgregarCasa, AgregarComercio
};

class ManejadorDeEventos {
public:
    explicit ManejadorDeEventos(RenderizadorServidorGrafico &rsg);

    SDL_Event *evento();

    void manejarEvento();

private:

    void manejarEventosInicial();

    bool escribirLetra();

    void manejarEventosNombrar();

    void manejarEventosFaltan2();

    void manejarEventosFalta1();

    void manejarEventosUnir();

    void manejarEventosPrincipal();

    void manejarEventosAgregarCasa();

    void manejarEventosAgregarComercio();

    SDL_Event _e;
    RenderizadorServidorGrafico _rsg;
    Estado _estadoActual;
};

bool enRango(int x, int y, int x_desde, int x_hasta, int y_desde, int y_hasta);

#endif // MANEJADORDEEVENTOS_H
