#include "ManejadorDeEventos.h"

ManejadorDeEventos::ManejadorDeEventos(RenderizadorServidorGrafico &rsg) : _e(), _rsg(rsg), _estadoActual(Inicial) {
    _rsg.mostrarPantallaInicial();
}

SDL_Event *ManejadorDeEventos::evento() {
    return &_e;
}

void ManejadorDeEventos::manejarEvento() {
    switch (_estadoActual) {
        case Inicial:
            manejarEventosInicial();
            break;
        case Nombrar:
            manejarEventosNombrar();
            break;
        case Faltan2:
            manejarEventosFaltan2();
            break;
        case Falta1:
            manejarEventosFalta1();
            break;
        case Unir:
            manejarEventosUnir();
            break;
        case Principal:
            manejarEventosPrincipal();
            break;
        case AgregarCasa:
            manejarEventosAgregarCasa();
            break;
        case AgregarComercio:
            manejarEventosAgregarComercio();
            break;
    }
}

void ManejadorDeEventos::manejarEventosInicial() {
    if (_e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (enRango(x, y, INICIO_BOTON_INICIAL_X, INICIO_BOTON_INICIAL_X + BOTON_ANCHO, INICIO_BOTON_INICIAL_Y,
                    INICIO_BOTON_INICIAL_Y + BOTONES_ALTO)) {
            _rsg.empezarNombrarPartida();
            _estadoActual = Nombrar;
        } else {
            for (int i = 0; i < _rsg.cantidadJugadores(); ++i) {
                if (enRango(x, y, INICIO_MAS_UNIR_X, INICIO_MAS_UNIR_X + MAS_ANCHO, INICIO_MAS_Y + FILA_ALTO * i,
                            INICIO_MAS_Y + MAS_ALTO + FILA_ALTO * i)) {
                    _rsg.empezarUnion(i);
                    _estadoActual = Unir;
                }
                if (enRango(x, y, INICIO_MAS_ABRIR_X, INICIO_MAS_ABRIR_X + MAS_ANCHO, INICIO_MAS_Y + FILA_ALTO * i,
                            INICIO_MAS_Y + MAS_ALTO + FILA_ALTO * i)) {
                    _rsg.abrirPartida(i);
                    _estadoActual = Principal;
                }
            }
        }
    }
}

bool ManejadorDeEventos::escribirLetra() {
    if (_e.type == SDL_KEYDOWN) {
        if (_e.key.keysym.sym >= SDLK_a && _e.key.keysym.sym <= SDLK_z) {
            _rsg.nombrarPartida(_e.key.keysym.sym - SDLK_a);
            return true;
        }
    }
    return false;
}

void ManejadorDeEventos::manejarEventosNombrar() {
    bool esLetra = escribirLetra();
    if (esLetra) {
        _estadoActual = Faltan2;
    }
}

void ManejadorDeEventos::manejarEventosFaltan2() {
    bool esLetra = escribirLetra();
    if (esLetra) {
        _estadoActual = Falta1;
    }
}

void ManejadorDeEventos::manejarEventosFalta1() {
    bool esLetra = escribirLetra();
    if (esLetra) {
        _estadoActual = Inicial;
    }
}

void ManejadorDeEventos::manejarEventosUnir() {
    if (_e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        for (int i = 0; i < _rsg.cantidadJugadores(); ++i) {
            if (enRango(x, y, INICIO_MAS_UNIR_X, INICIO_MAS_UNIR_X + MAS_ANCHO, INICIO_MAS_Y + FILA_ALTO * i,
                        INICIO_MAS_Y + MAS_ALTO + FILA_ALTO * i)) {
                _rsg.unir(i);
                _estadoActual = Inicial;
            }
        }
    }
}

void ManejadorDeEventos::manejarEventosPrincipal() {
    if (_e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (enRango(x, y, INICIO_BOTON_X, INICIO_BOTON_X + BOTON_ANCHO, INICIO_BOTON_CASA_Y,
                    INICIO_BOTON_CASA_Y + BOTONES_ALTO)) {
            _rsg.empezarAgregarCasa();
            _estadoActual = AgregarCasa;
        } else if (enRango(x, y, INICIO_BOTON_X, INICIO_BOTON_X + BOTON_ANCHO, INICIO_BOTON_COMERCIO_Y,
                           INICIO_BOTON_COMERCIO_Y + BOTONES_ALTO)) {
            _rsg.empezarAgregarComercio();
            _estadoActual = AgregarComercio;
        } else if (enRango(x, y, INICIO_BOTON_X, INICIO_BOTON_X + BOTON_ANCHO, INICIO_BOTON_AVANZAR_Y,
                           INICIO_BOTON_AVANZAR_Y + BOTONES_ALTO)) {
            _rsg.avanzarTurno();
        } else if (enRango(x, y, INICIO_BOTON_X, INICIO_BOTON_X + BOTON_ANCHO, INICIO_BOTON_VOLVER_Y,
                           INICIO_BOTON_VOLVER_Y + BOTON_VOLVER_ALTO)) {
            _rsg.cerrarPartida();
            _estadoActual = Inicial;
        } else if (enRango(x, y, INICIO_MAPA_X, FIN_MAPA_X, INICIO_MAPA_Y, FIN_MAPA_Y)) {
            x -= INICIO_MAPA_X;
            y -= INICIO_MAPA_Y;
            x = x / SPRITE_ANCHO;
            y = y / SPRITE_ALTO;
            _rsg.mostrarNivel({x, y});
        }
    } else if (_e.type == SDL_KEYDOWN) {
        switch (_e.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
                _rsg.desplazarCentro(Arriba);
                break;

            case SDLK_DOWN:
            case SDLK_s:
                _rsg.desplazarCentro(Abajo);
                break;

            case SDLK_LEFT:
            case SDLK_a:
                _rsg.desplazarCentro(Izquierda);
                break;

            case SDLK_RIGHT:
            case SDLK_d:
                _rsg.desplazarCentro(Derecha);
                break;

            default:
                break;
        }
    }
}

void ManejadorDeEventos::manejarEventosAgregarCasa() {
    if (_e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (enRango(x, y, INICIO_MAPA_X, FIN_MAPA_X, INICIO_MAPA_Y, FIN_MAPA_Y)) {
            x -= INICIO_MAPA_X;
            y -= INICIO_MAPA_Y;
            x = x / SPRITE_ANCHO;
            y = y / SPRITE_ALTO;
            _rsg.agregarCasa({x, y});
            _estadoActual = Principal;
        }
    }
}

void ManejadorDeEventos::manejarEventosAgregarComercio() {
    if (_e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (enRango(x, y, INICIO_MAPA_X, FIN_MAPA_X, INICIO_MAPA_Y, FIN_MAPA_Y)) {
            x -= INICIO_MAPA_X;
            y -= INICIO_MAPA_Y;
            x = x / SPRITE_ANCHO;
            y = y / SPRITE_ALTO;
            _rsg.agregarComercio({x, y});
            _estadoActual = Principal;
        }
    }
}

bool enRango(int x, int y, int x_desde, int x_hasta, int y_desde, int y_hasta) {
    return x >= x_desde and x < x_hasta and y >= y_desde and y < y_hasta;
}
