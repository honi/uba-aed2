#ifndef TP_SIMCITY_SERVIDOR_H
#define TP_SIMCITY_SERVIDOR_H

#include "Tipos.h"
#include "Mapa.h"
#include "SimCity.h"
#include "string_map.h"

class Servidor {
public:
    Servidor();
    ~Servidor();
    void nuevaCiudad(const Jugador& j, const Mapa& m);
    void agregarCasa(const Jugador& j, const Casilla& c);
    void agregarComercio(const Jugador& j, const Casilla& c);
    void avanzarTurno(const Jugador& j);
    void unir(const Jugador& j1, const Jugador& j2);
    bool huboConstruccion(const Jugador& j) const;
    Mapa mapa(const Jugador& j) const;
    map<Casilla, Nivel> casas(const Jugador& j) const;
    map<Casilla, Nivel> comercios(const Jugador& j) const;
    Nat popularidad(const Jugador& j) const;
    Nat antiguedad(const Jugador& j) const;

private:
    string_map<SimCity*> _ciudades;
};

#endif //TP_SIMCITY_SERVIDOR_H
