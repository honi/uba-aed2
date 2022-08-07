#include "aed2_Servidor.h"

aed2_Servidor::aed2_Servidor(): _servidor() {}

void aed2_Servidor::nuevaPartida(Jugador j, set<int> horizontales, set<int> verticales) {
    _servidor.nuevaCiudad(j, Mapa(horizontales, verticales));
}

void aed2_Servidor::agregarCasa(Jugador j, Casilla c) {
    _servidor.agregarCasa(j, c);
}

void aed2_Servidor::agregarComercio(Jugador j, Casilla c) {
    _servidor.agregarComercio(j, c);
}

void aed2_Servidor::avanzarTurno(Jugador j) {
    _servidor.avanzarTurno(j);
}

void aed2_Servidor::unir(Jugador j1, Jugador j2) {
    _servidor.unir(j1, j2);
}

set<int> aed2_Servidor::riosHorizontales(Jugador j) const {
    return _servidor.mapa(j).horizontales();
}

set<int> aed2_Servidor::riosVerticales(Jugador j) const {
    return _servidor.mapa(j).verticales();
}

set<Casilla> aed2_Servidor::casas(Jugador j) const {
    // Devolvemos solo las claves del diccionario(Casilla, Nivel) casas de nuestro servidor.
    return keys(_servidor.casas(j));
}

set<Casilla> aed2_Servidor::comercios(Jugador j) const {
    // Devolvemos solo las claves del diccionario(Casilla, Nivel) comercios de nuestro servidor.
    return keys(_servidor.comercios(j));
}

Nat aed2_Servidor::nivel(Jugador j, Casilla c) const {
    // Para saber el nivel de una casilla, tenemos que buscarla en el diccionario de casas o comercios de nuestro servidor.
    map<Casilla, Nivel> casas = _servidor.casas(j);
    if (casas.count(c)) {
        return casas[c];
    } else {
        // Si la casilla tampoco corresponde a un comercio, el map devuelve el valor default para Nivel que es 0.
        map<Casilla, Nivel> comercios = _servidor.comercios(j);
        return comercios[c];
    }
}

bool aed2_Servidor::huboConstruccion(Jugador j) const {
    return _servidor.huboConstruccion(j);
}

Nat aed2_Servidor::popularidad(Jugador j) const {
    return _servidor.popularidad(j);
}

Nat aed2_Servidor::antiguedad(Jugador j) const {
    return _servidor.antiguedad(j);
}
