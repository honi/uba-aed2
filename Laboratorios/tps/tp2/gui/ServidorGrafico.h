#ifndef SERVIDORGRAFICO_H
#define SERVIDORGRAFICO_H

#include "../src/aed2_Servidor.h"

const int tamanio_cuadricula = 11;
const int tamanio_cuadrante = 5;

enum TipoPosicion {
    Nada, RioHorizontal, RioVertical, RioAmbos, Casa0, Comercio0, Casa, Comercio
};

enum DireccionMovimiento {
    Arriba, Abajo, Derecha, Izquierda
};

class ServidorGrafico {
public:

    ServidorGrafico(aed2_Servidor &s);

    void nuevaPartida(Jugador j);

    void agregarCasa(Casilla c);

    void agregarComercio(Casilla c);

    bool avanzarTurno();

    void unir(Nat ij1, Nat ij2);

    Nat nivel(Casilla c, bool mover) const;

    Nat popularidad() const;

    Nat antiguedad() const;

    TipoPosicion tipoPosicion(Nat y, Nat x) const;

    Jugador jugador(Nat indice) const;

    Jugador jugadorActual() const;

    void abrirPartida(Nat indice);

    void cerrarPartida();

    void desplazarCentro(DireccionMovimiento direccion);

private:

    set<int> riosHorizontales() const;

    set<int> riosVerticales() const;

    set<Casilla> casas() const;

    set<Casilla> comercios() const;

    void escanearAlrededores();

    struct InformacionSimCity {
        int centroX;
        int centroY;
        vector<vector<TipoPosicion> > mapaActual;
    };

    aed2_Servidor _servidor;
    Nat _indiceJugadorActual;
    vector<pair<Jugador, InformacionSimCity> > _simCitys;
};

#endif // SERVIDORGRAFICO_H
