#include "SimCity.h"

// Funciones públicas

SimCity::SimCity(Mapa m):
        _mapa(m),
        _turnos(0),
        _maxTurnos(0),
        _popularidad(0),
        _huboConstruccion(false),
        _casas(),
        _comercios(),
        _uniones() {}

void SimCity::agregarCasa(const Casilla& c) {
    _casas[c] = _turnos;
    _huboConstruccion = true;
}

void SimCity::agregarComercio(const Casilla& c) {
    _comercios[c] = _turnos;
    _huboConstruccion = true;
}

void SimCity::avanzarTurno() {
    _turnos++;
    _maxTurnos++;
    _huboConstruccion = false;
}

void SimCity::unir(SimCity* otro) {
    _uniones.emplace_back(otro, _turnos);
    _maxTurnos = max(_maxTurnos, otro->antiguedad());
    _popularidad += otro->popularidad() + 1;
    _huboConstruccion = _huboConstruccion or otro->huboConstruccion();
}

bool SimCity::huboConstruccion() const {
    return _huboConstruccion;
}

Mapa SimCity::mapa() const {
    list<Mapa> mapasUniones;
    for (Union u: _uniones) {
        mapasUniones.push_back(u.first->mapa());
    }
    return _mapa.unir(mapasUniones);
}

map<Casilla, Nivel> SimCity::casas() const {
    map<Casilla, Nivel> casas = casasPropias();
    unirConstrucciones(casas, casasUniones());
    return casas;
}

map<Casilla, Nivel> SimCity::comercios() const {
    map<Casilla, Nivel> todasLasCasas = casas();
    map<Casilla, Nivel> comercios = comerciosPropios();
    unirConstrucciones(comercios, comerciosUniones());
    sacarComerciosSolapados(comercios, todasLasCasas);
    adoptarNiveles(comercios, todasLasCasas);
    return comercios;
}

Nat SimCity::popularidad() const {
    return _popularidad;
}

Nat SimCity::antiguedad() const {
    return _maxTurnos;
}

// Funciones privadas

map<Casilla, Nivel> SimCity::casasPropias() const {
    map<Casilla, Nivel> res;
    for (auto it = _casas.begin(); it != _casas.end(); it++) {
        Casilla casillaCasa = it->first;
        Nat turnosCreacion = it->second;
        res[casillaCasa] = _turnos - turnosCreacion;
    }
    return res;
}

map<Casilla, Nivel> SimCity::casasUniones() const {
    map<Casilla, Nivel> res;
    for (auto it = _uniones.begin(); it != _uniones.end(); it++) {
        SimCity* sUnion = it->first;
        Nat turnosUnion = it->second;
        Nat turnosDesdeLaUnion = _turnos - turnosUnion;
        map<Casilla, Nivel> casasUnion = sUnion->casas();
        sumarATodos(casasUnion, turnosDesdeLaUnion);
        unirConstrucciones(res, casasUnion);
    }
    return res;
}

map<Casilla, Nivel> SimCity::comerciosPropios() const {
    map<Casilla, Nivel> res;
    for (auto it = _comercios.begin(); it != _comercios.end(); it++) {
        Casilla casillaComercio = it->first;
        Nat turnosCreacion = it->second;
        res[casillaComercio] = _turnos - turnosCreacion;
    }
    return res;
}

map<Casilla, Nivel> SimCity::comerciosUniones() const {
    map<Casilla, Nivel> res;
    for (auto it = _uniones.begin(); it != _uniones.end(); it++) {
        SimCity* sUnion = it->first;
        Nat turnosUnion = it->second;
        Nat turnosDesdeLaUnion = _turnos - turnosUnion;
        map<Casilla, Nivel> comerciosUnion = sUnion->comercios();
        sumarATodos(comerciosUnion, turnosDesdeLaUnion);
        unirConstrucciones(res, comerciosUnion);
    }
    return res;
}

void SimCity::unirConstrucciones(map<Casilla, Nivel>& dst, const map<Casilla, Nivel>& src) const {
    for (auto it = src.begin(); it != src.end(); it++) {
        Casilla casilla = it->first;
        Nivel nivelSrc = it->second;
        dst[casilla] = max(dst[casilla], nivelSrc);
    }
}

void SimCity::sacarComerciosSolapados(map<Casilla, Nivel>& comercios, const map<Casilla, Nivel>& casas) const {
    auto it = comercios.begin();
    while (it != comercios.end()) {
        Casilla casillaComercio = it->first;
        if (casas.count(casillaComercio) == 1) {
            it = comercios.erase(it);
        } else {
            it++;
        }
    }
}

void SimCity::adoptarNiveles(map<Casilla, Nivel>& comercios, const map<Casilla, Nivel>& casas) const {
    for (auto it = comercios.begin(); it != comercios.end(); it++) {
        Casilla casillaComercio = it->first;
        Nivel nivelComercio = it->second;
        Nivel nivelManhattan = obtenerNivelManhattan(casillaComercio, casas);
        comercios[casillaComercio] = max(nivelComercio, nivelManhattan);
    }
}

Nat SimCity::obtenerNivelManhattan(Casilla casillaComercio, const map<Casilla, Nivel>& casas) const {
    Nat res = 0;
    for (auto it = casas.begin(); it != casas.end(); it++) {
        Casilla casillaCasa = it->first;
        Nivel nivelCasa = it->second;
        Nat distanciaManhattanCasa = distanciaManhattan(casillaComercio, casillaCasa);
        if (distanciaManhattanCasa <= 3) {
            res = max(nivelCasa, res);
        }
    }
    return res;
}
