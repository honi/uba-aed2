#include <utility>
#include <list>

using namespace std;

// Ejercicio 15

using Pos = pair<int, int>;

const char ARRIBA = '^';
const char ABAJO = 'v';
const char DERECHA = '<';
const char IZQUIERDA = '>';

class Pocion {
public:
    Pocion(uint movimientos, uint turnos);

    uint movimientos();

    uint turnos();

    void proximo_turno();

private:
    uint _movimientos;
    uint _turnos;
};

Pocion::Pocion(uint movimientos, uint turnos) : _movimientos(movimientos), _turnos(turnos) {}

uint Pocion::movimientos() {
    return _movimientos;
}

uint Pocion::turnos() {
    return _turnos;
}

void Pocion::proximo_turno() {
    _turnos--;
}

class Juego {
public:
    Juego(uint casilleros, Pos pos_inicial);

    Pos posicion_jugador();

    uint turno_actual();

    void mover_jugador(char dir);

    void ingerir_pocion(uint movimientos, uint turnos);

private:
    uint _casilleros;
    Pos _posicion;
    uint _turno;
    uint _movimientos_realizados;

    uint _movimientos_disponibles();

    void _proximo_turno();

    list<Pocion> _pociones;
};

Juego::Juego(uint casilleros, Pos pos_inicial) : _casilleros(casilleros), _posicion(pos_inicial), _turno(0),
                                                 _movimientos_realizados(0) {}

Pos Juego::posicion_jugador() {
    return _posicion;
}

uint Juego::turno_actual() {
    return _turno;
}

void Juego::mover_jugador(char dir) {
    bool movida_valida = false;
    switch (dir) {
        case ARRIBA:
            if (_posicion.first > 0) {
                _posicion.first--;
                movida_valida = true;
            }
            break;
        case ABAJO:
            if (_posicion.first < _casilleros - 1) {
                _posicion.first++;
                movida_valida = true;
            }
            break;
        case DERECHA:
            if (_posicion.second < _casilleros - 1) {
                _posicion.second++;
                movida_valida = true;
            }
            break;
        case IZQUIERDA:
            if (_posicion.second > 0) {
                _posicion.second--;
                movida_valida = true;
            }
            break;
    }
    if (movida_valida) {
        if (++_movimientos_realizados == _movimientos_disponibles()) {
            _proximo_turno();
        }
    }
}

void Juego::ingerir_pocion(uint movimientos, uint turnos) {
    _pociones.push_back(Pocion(movimientos, turnos));
}

uint Juego::_movimientos_disponibles() {
    if (_pociones.size() == 0) {
        // Siempre hay al menos 1 movimiento disponible por turno.
        return 1;
    }
    uint res = 0;
    for (auto p: _pociones) {
        res += p.movimientos();
    }
    return res;
}

void Juego::_proximo_turno() {
    _turno++;
    _movimientos_realizados = 0;
    for (auto p = _pociones.begin(); p != _pociones.end(); p++) {
        p->proximo_turno();
        if (p->turnos() == 0) {
            _pociones.erase(p);
        }
    }
}
