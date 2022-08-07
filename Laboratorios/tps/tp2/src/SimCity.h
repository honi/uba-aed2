#ifndef TP_SIMCITY_SIMCITY_H
#define TP_SIMCITY_SIMCITY_H

#include "Tipos.h"
#include "Utils.h"
#include "Mapa.h"

class SimCity {
    using Union = pair<SimCity*, Nat>;

public:
    SimCity(Mapa);
    void agregarCasa(const Casilla&);
    void agregarComercio(const Casilla&);
    void avanzarTurno();
    void unir(SimCity*);
    bool huboConstruccion() const;
    Mapa mapa() const;
    map<Casilla, Nivel> casas() const;
    map<Casilla, Nivel> comercios() const;
    Nat popularidad() const;
    Nat antiguedad() const;

private:
    Mapa _mapa;
    Nat _turnos;
    Nat _maxTurnos;
    Nat _popularidad;
    bool _huboConstruccion;
    // Por enunciado, estos map son diccionarios lineales y por lo tanto definir nuevas claves es O(1).
    map<Casilla, Nat> _casas;
    map<Casilla, Nat> _comercios;
    list<Union> _uniones;
    map<Casilla, Nivel> casasPropias() const;
    map<Casilla, Nivel> casasUniones() const;
    map<Casilla, Nivel> comerciosPropios() const;
    map<Casilla, Nivel> comerciosUniones() const;
    void unirConstrucciones(map<Casilla, Nivel>&, const map<Casilla, Nivel>&) const;
    void sacarComerciosSolapados(map<Casilla, Nivel>&, const map<Casilla, Nivel>&) const;
    void adoptarNiveles(map<Casilla, Nivel>&, const map<Casilla, Nivel>&) const;
    Nat obtenerNivelManhattan(Casilla, const map<Casilla, Nivel>&) const;
};

#endif //TP_SIMCITY_SIMCITY_H
