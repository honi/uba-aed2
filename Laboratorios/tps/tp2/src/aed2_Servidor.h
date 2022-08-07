#ifndef AED2_SERVIDOR_H
#define AED2_SERVIDOR_H

#include "Tipos.h"
#include "Utils.h"
#include "Servidor.h"

class aed2_Servidor {
public:
    aed2_Servidor();
    void nuevaPartida(Jugador j, set<int> horizontales, set<int> verticales);
    void agregarCasa(Jugador j, Casilla c);
    void agregarComercio(Jugador j, Casilla c);
    void avanzarTurno(Jugador j);
    void unir(Jugador j1, Jugador j2);
    set<int> riosHorizontales(Jugador j) const;
    set<int> riosVerticales(Jugador j) const;
    set<Casilla> casas(Jugador j) const;
    set<Casilla> comercios(Jugador j) const;
    Nat nivel(Jugador j, Casilla c) const;
    bool huboConstruccion(Jugador j) const;
    Nat popularidad(Jugador j) const;
    Nat antiguedad(Jugador j) const;

private:
    Servidor _servidor;
};

#endif // AED2_SERVIDOR_H
