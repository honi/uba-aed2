#include "ServidorGrafico.h"

using namespace std;

ServidorGrafico::ServidorGrafico(aed2_Servidor &s) : _servidor(s), _indiceJugadorActual(-1) {}

void ServidorGrafico::nuevaPartida(Jugador j) {
    int rioH = (rand() % tamanio_cuadricula) - tamanio_cuadrante;
    int rioV = (rand() % tamanio_cuadricula) - tamanio_cuadrante;
    _servidor.nuevaPartida(j, {rioH}, {rioV});
    vector<vector<TipoPosicion> > mapaJ(tamanio_cuadricula, vector<TipoPosicion>(tamanio_cuadricula, Nada));
    _simCitys.push_back({j, {0, 0, mapaJ}});
}

void ServidorGrafico::agregarCasa(Casilla c) {
    int xReal = c.first + _simCitys[_indiceJugadorActual].second.centroX - tamanio_cuadrante;
    int yReal = _simCitys[_indiceJugadorActual].second.centroY + tamanio_cuadrante - c.second;
    _servidor.agregarCasa(jugadorActual(), {xReal, yReal});
    escanearAlrededores();
}

void ServidorGrafico::agregarComercio(Casilla c) {
    int xReal = c.first + _simCitys[_indiceJugadorActual].second.centroX - tamanio_cuadrante;
    int yReal = _simCitys[_indiceJugadorActual].second.centroY + tamanio_cuadrante - c.second;
    _servidor.agregarComercio(jugadorActual(), {xReal, yReal});
    escanearAlrededores();
}

bool ServidorGrafico::avanzarTurno() {
    if (_servidor.huboConstruccion(jugadorActual())) {
        _servidor.avanzarTurno(jugadorActual());
        escanearAlrededores();
        return true;
    }
    return false;
}

void ServidorGrafico::unir(Nat ij1, Nat ij2) {
    _servidor.unir(_simCitys[ij1].first, _simCitys[ij2].first);
}

Nat ServidorGrafico::nivel(Casilla c, bool mover) const {
    if (mover) {
        int xReal = c.first + _simCitys[_indiceJugadorActual].second.centroX - tamanio_cuadrante;
        int yReal = _simCitys[_indiceJugadorActual].second.centroY + tamanio_cuadrante - c.second;
        return _servidor.nivel(jugadorActual(), {xReal, yReal});
    }
    return _servidor.nivel(jugadorActual(), c);
}

Nat ServidorGrafico::popularidad() const {
    return _servidor.popularidad(jugadorActual());
}

Nat ServidorGrafico::antiguedad() const {
    return _servidor.antiguedad(jugadorActual());
}

TipoPosicion ServidorGrafico::tipoPosicion(Nat y, Nat x) const {
    return _simCitys[_indiceJugadorActual].second.mapaActual[y][x];
}

Jugador ServidorGrafico::jugador(Nat indice) const {
    return _simCitys[indice].first;
}

Jugador ServidorGrafico::jugadorActual() const {
    return jugador(_indiceJugadorActual);
}

void ServidorGrafico::abrirPartida(Nat indice) {
    _indiceJugadorActual = indice;
    escanearAlrededores();
}

void ServidorGrafico::cerrarPartida() {
    _indiceJugadorActual = -1;
}

void ServidorGrafico::desplazarCentro(DireccionMovimiento direccion) {
    int salto = 4;
    switch (direccion) {
        case Arriba:
            _simCitys[_indiceJugadorActual].second.centroY += salto;
            break;
        case Abajo:
            _simCitys[_indiceJugadorActual].second.centroY -= salto;
            break;
        case Derecha:
            _simCitys[_indiceJugadorActual].second.centroX += salto;
            break;
        case Izquierda:
            _simCitys[_indiceJugadorActual].second.centroX -= salto;
            break;
    }
    escanearAlrededores();
}

void ServidorGrafico::escanearAlrededores() {
    int xReal, yReal;
    set<int> riosH = riosHorizontales();
    set<int> riosV = riosVerticales();
    set<Casilla> cas = casas();
    set<Casilla> cos = comercios();
    for (int y = 0; y < tamanio_cuadricula; ++y) {
        for (int x = 0; x < tamanio_cuadricula; ++x) {
            xReal = x + _simCitys[_indiceJugadorActual].second.centroX - tamanio_cuadrante;
            yReal = y + _simCitys[_indiceJugadorActual].second.centroY - tamanio_cuadrante;
            if (riosH.count(yReal) && riosV.count(xReal)) {
                _simCitys[_indiceJugadorActual].second.mapaActual[y][x] = RioAmbos;
            } else if (riosH.count(yReal)) {
                _simCitys[_indiceJugadorActual].second.mapaActual[y][x] = RioHorizontal;
            } else if (riosV.count(xReal)) {
                _simCitys[_indiceJugadorActual].second.mapaActual[y][x] = RioVertical;
            } else if (cas.count({xReal, yReal})) {
                if (nivel({xReal, yReal}, false) == 0) {
                    _simCitys[_indiceJugadorActual].second.mapaActual[y][x] = Casa0;
                } else {
                    _simCitys[_indiceJugadorActual].second.mapaActual[y][x] = Casa;
                }
            } else if (cos.count({xReal, yReal})) {
                if (nivel({xReal, yReal}, false) == 0) {
                    _simCitys[_indiceJugadorActual].second.mapaActual[y][x] = Comercio0;
                } else {
                    _simCitys[_indiceJugadorActual].second.mapaActual[y][x] = Comercio;
                }
            } else {
                _simCitys[_indiceJugadorActual].second.mapaActual[y][x] = Nada;
            }
        }
    }
}

set<int> ServidorGrafico::riosHorizontales() const {
    return _servidor.riosHorizontales(jugadorActual());
}

set<int> ServidorGrafico::riosVerticales() const {
    return _servidor.riosVerticales(jugadorActual());
}

set<Casilla> ServidorGrafico::casas() const {
    return _servidor.casas(jugadorActual());
}

set<Casilla> ServidorGrafico::comercios() const {
    return _servidor.comercios(jugadorActual());
}
