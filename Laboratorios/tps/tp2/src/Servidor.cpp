#include "Servidor.h"

Servidor::Servidor(): _ciudades() {}

Servidor::~Servidor() {
    for (const Jugador& j: _ciudades.keys()) {
        delete _ciudades[j];
    }
}

void Servidor::nuevaCiudad(const Jugador& j, const Mapa& m) {
    _ciudades[j] = new SimCity(m);
}

void Servidor::agregarCasa(const Jugador& j, const Casilla& c) {
    _ciudades[j]->agregarCasa(c);
}

void Servidor::agregarComercio(const Jugador& j, const Casilla& c) {
    _ciudades[j]->agregarComercio(c);
}

void Servidor::avanzarTurno(const Jugador& j) {
    _ciudades[j]->avanzarTurno();
}

void Servidor::unir(const Jugador& j1, const Jugador& j2) {
    _ciudades[j1]->unir(_ciudades[j2]);
}

bool Servidor::huboConstruccion(const Jugador& j) const {
    return _ciudades[j]->huboConstruccion();
}

Mapa Servidor::mapa(const Jugador& j) const {
    return _ciudades[j]->mapa();
}

map<Casilla, Nivel> Servidor::casas(const Jugador& j) const {
    return _ciudades[j]->casas();
}

map<Casilla, Nivel> Servidor::comercios(const Jugador& j) const {
    return _ciudades[j]->comercios();
}

Nat Servidor::popularidad(const Jugador& j) const {
    return _ciudades[j]->popularidad();
}

Nat Servidor::antiguedad(const Jugador& j) const {
    return _ciudades[j]->antiguedad();
}
