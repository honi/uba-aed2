#include "RenderizadorServidorGrafico.h"

//The window renderer
SDL_Renderer *renderizador = nullptr;

//Scene sprites
SDL_Rect sprites[40];
SDL_Rect numeros[10];
SDL_Rect letras[27];
SDL_Rect botones[6];
SDL_Rect mas[2];
SDL_Rect pantallaInicial;
SDL_Rect pantallaPrincipal;
Textura texturaSprites;
Textura texturaNumeros;
Textura texturaLetras;
Textura texturaBotones;
Textura texturaMas;
Textura texturaPantallaInicial;
Textura texturaPantallaPrincipal;

RenderizadorServidorGrafico::RenderizadorServidorGrafico(ServidorGrafico &sg) : _servidorGrafico(sg),
                                                                                _cantidadJugadores(0),
                                                                                _nuevoJugador(""), _partidaUnir(-1) {}

void RenderizadorServidorGrafico::mostrarPantallaInicial() {
    renderizarPantallaInicial();
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::empezarNombrarPartida() {
    texturaBotones.renderizar(INICIO_BOTON_INICIAL_X, INICIO_BOTON_INICIAL_Y, renderizador, &botones[1]);
    texturaLetras.renderizar(INICIO_NOMBRES_X, INICIO_NOMBRES_Y + FILA_ALTO * _cantidadJugadores, renderizador,
                             &letras[26]);
    texturaLetras.renderizar(INICIO_NOMBRES_X + LETRA_ANCHO, INICIO_NOMBRES_Y + FILA_ALTO * _cantidadJugadores,
                             renderizador, &letras[26]);
    texturaLetras.renderizar(INICIO_NOMBRES_X + LETRA_ANCHO * 2, INICIO_NOMBRES_Y + FILA_ALTO * _cantidadJugadores,
                             renderizador, &letras[26]);
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::nombrarPartida(int indice) {
    texturaLetras.renderizar(INICIO_NOMBRES_X + LETRA_ANCHO * _nuevoJugador.size(),
                             INICIO_NOMBRES_Y + FILA_ALTO * _cantidadJugadores, renderizador,
                             &letras[indice]);
    _nuevoJugador.push_back('a' + indice);
    if (_nuevoJugador.size() == 3) {
        nuevaPartida(_nuevoJugador);
    }
    renderizarListaPartidas();
    SDL_RenderPresent(renderizador);
}

Nat RenderizadorServidorGrafico::cantidadJugadores() const {
    return _cantidadJugadores;
}

void RenderizadorServidorGrafico::empezarUnion(int indice) {
    _partidaUnir = indice;
    texturaMas.renderizar(INICIO_MAS_UNIR_X, INICIO_MAS_Y + FILA_ALTO * indice, renderizador, &mas[1]);
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::unir(int indice) {
    if (indice != _partidaUnir) {
        _servidorGrafico.unir(_partidaUnir, indice);
        texturaMas.renderizar(INICIO_MAS_UNIR_X, INICIO_MAS_Y + FILA_ALTO * indice, renderizador, &mas[1]);
        SDL_RenderPresent(renderizador);
        SDL_Delay(100);
    }
    texturaMas.renderizar(INICIO_MAS_UNIR_X, INICIO_MAS_Y + FILA_ALTO * indice, renderizador, &mas[0]);
    texturaMas.renderizar(INICIO_MAS_UNIR_X, INICIO_MAS_Y + FILA_ALTO * _partidaUnir, renderizador, &mas[0]);
    _partidaUnir = -1;
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::abrirPartida(int indice) {
    if (indice < _cantidadJugadores) {
        texturaPantallaPrincipal.renderizar(0, 0, renderizador, &pantallaPrincipal);
        _servidorGrafico.abrirPartida(indice);
        renderizarNombreActual();
        renderizarAntiguedad();
        renderizarPopularidad();
        renderizarNivelVacio();
        texturaBotones.renderizar(INICIO_BOTON_X, 361, renderizador, &botones[2]);
        texturaBotones.renderizar(INICIO_BOTON_X, 426, renderizador, &botones[4]);
        renderizarMapaCompleto();
        SDL_RenderPresent(renderizador);
    }
}

void RenderizadorServidorGrafico::empezarAgregarCasa() {
    texturaBotones.renderizar(INICIO_BOTON_X, INICIO_BOTON_CASA_Y, renderizador, &botones[3]);
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::agregarCasa(Casilla c) {
    _servidorGrafico.agregarCasa(c);
    texturaBotones.renderizar(INICIO_BOTON_X, INICIO_BOTON_CASA_Y, renderizador, &botones[2]);
    renderizarMapaCompleto();
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::empezarAgregarComercio() {
    texturaBotones.renderizar(INICIO_BOTON_X, INICIO_BOTON_COMERCIO_Y, renderizador, &botones[5]);
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::agregarComercio(Casilla c) {
    _servidorGrafico.agregarComercio(c);
    texturaBotones.renderizar(INICIO_BOTON_X, INICIO_BOTON_COMERCIO_Y, renderizador, &botones[4]);
    renderizarMapaCompleto();
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::mostrarNivel(Casilla c) {
    Nat nivel = _servidorGrafico.nivel(c, true);
    renderizarPosicion(c.first, 10 - c.second, _servidorGrafico.tipoPosicion(10 - c.second, c.first), true);
    renderizarNivel(nivel);
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::desplazarCentro(DireccionMovimiento direccion) {
    _servidorGrafico.desplazarCentro(direccion);
    renderizarMapaCompleto();
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::avanzarTurno() {
    if (_servidorGrafico.avanzarTurno()) {
        renderizarMapaCompleto();
        renderizarAntiguedad();
        SDL_RenderPresent(renderizador);
    }
}

void RenderizadorServidorGrafico::cerrarPartida() {
    _servidorGrafico.cerrarPartida();
    renderizarPantallaInicial();
    renderizarListaPartidas();
    SDL_RenderPresent(renderizador);
}

void RenderizadorServidorGrafico::nuevaPartida(Jugador j) {
    _servidorGrafico.nuevaPartida(j);
    texturaMas.renderizar(INICIO_MAS_UNIR_X, INICIO_MAS_Y + FILA_ALTO * _cantidadJugadores, renderizador, &mas[0]);
    texturaMas.renderizar(INICIO_MAS_ABRIR_X, INICIO_MAS_Y + FILA_ALTO * _cantidadJugadores, renderizador, &mas[0]);
    texturaBotones.renderizar(INICIO_BOTON_INICIAL_X, INICIO_BOTON_INICIAL_Y, renderizador, &botones[0]);
    _cantidadJugadores += 1;
    _nuevoJugador = "";
}

void RenderizadorServidorGrafico::renderizarPantallaInicial() {
    texturaPantallaInicial.renderizar(0, 0, renderizador, &pantallaInicial);
    texturaBotones.renderizar(INICIO_BOTON_INICIAL_X, INICIO_BOTON_INICIAL_Y, renderizador, &botones[0]);
}

void RenderizadorServidorGrafico::renderizarListaPartidas() {
    for (int i = 0; i < _cantidadJugadores; ++i) {
        Jugador jugador = _servidorGrafico.jugador(i);
        texturaLetras.renderizar(INICIO_NOMBRES_X, INICIO_NOMBRES_Y + FILA_ALTO * i, renderizador,
                                 &letras[jugador[0] - 'a']);
        texturaLetras.renderizar(INICIO_NOMBRES_X + LETRA_ANCHO, INICIO_NOMBRES_Y + FILA_ALTO * i, renderizador,
                                 &letras[jugador[1] - 'a']);
        texturaLetras.renderizar(INICIO_NOMBRES_X + LETRA_ANCHO * 2, INICIO_NOMBRES_Y + FILA_ALTO * i, renderizador,
                                 &letras[jugador[2] - 'a']);
        texturaMas.renderizar(INICIO_MAS_UNIR_X, INICIO_MAS_Y + FILA_ALTO * i, renderizador, &mas[0]);
        texturaMas.renderizar(INICIO_MAS_ABRIR_X, INICIO_MAS_Y + FILA_ALTO * i, renderizador, &mas[0]);
    }
}

void RenderizadorServidorGrafico::renderizarMapaCompleto() {
    for (int y = 0; y < tamanio_cuadricula; ++y) {
        for (int x = 0; x < tamanio_cuadricula; ++x) {
            renderizarPosicion(x, y, _servidorGrafico.tipoPosicion(y, x), false);
        }
    }
}

void RenderizadorServidorGrafico::renderizarPosicion(int x, int y, TipoPosicion tp, bool seleccionado) {
    Nat indice;
    if (tp == Nada) {
        indice = 0;
    } else if (tp == RioHorizontal) {
        indice = 1;
    } else if (tp == RioVertical) {
        indice = 2;
    } else if (tp == RioAmbos) {
        indice = 3;
    } else if (tp == Casa0) {
        indice = 4;
        if (seleccionado) {
            indice++;
        }
    } else if (tp == Comercio0) {
        indice = 6;
        if (seleccionado) {
            indice++;
        }
    } else if (tp == Casa) {
        indice = 8 + (2 * x) % 8 + y % 2;
        if (seleccionado) {
            indice += 8;
        }
    } else if (tp == Comercio) {
        indice = 24 + (2 * x) % 8 + y % 2;
        if (seleccionado) {
            indice += 8;
        }
    }
    texturaSprites.renderizar(COMIENZO_MAPA_X + SPRITE_ANCHO * x, COMIENZO_MAPA_Y - SPRITE_ALTO * y, renderizador,
                              &sprites[indice]);
}

void RenderizadorServidorGrafico::renderizarNombreActual() {
    string nombre = _servidorGrafico.jugadorActual();
    for (int i = 0; i < 3; ++i) {
        texturaLetras.renderizar(INICIO_LETRAS_X + i * LETRA_ANCHO, INICIO_NOMBRE_Y, renderizador,
                                 &letras[0 + nombre[i] - 'a']);
    }
}

void RenderizadorServidorGrafico::renderizarAntiguedad() {
    Nat antiguedad = _servidorGrafico.antiguedad();
    texturaNumeros.renderizar(INICIO_LETRAS_X, INICIO_ANTIGUEDAD_Y, renderizador, &numeros[antiguedad / 100 % 10]);
    texturaNumeros.renderizar(INICIO_LETRAS_X + LETRA_ANCHO, INICIO_ANTIGUEDAD_Y, renderizador,
                              &numeros[antiguedad / 10 % 10]);
    texturaNumeros.renderizar(INICIO_LETRAS_X + LETRA_ANCHO * 2, INICIO_ANTIGUEDAD_Y, renderizador,
                              &numeros[antiguedad % 10]);
}

void RenderizadorServidorGrafico::renderizarPopularidad() {
    Nat popularidad = _servidorGrafico.popularidad();
    texturaNumeros.renderizar(INICIO_LETRAS_X, INICIO_POPULARIDAD_Y, renderizador, &numeros[popularidad / 100 % 10]);
    texturaNumeros.renderizar(INICIO_LETRAS_X + LETRA_ANCHO, INICIO_POPULARIDAD_Y, renderizador,
                              &numeros[popularidad / 10 % 10]);
    texturaNumeros.renderizar(INICIO_LETRAS_X + LETRA_ANCHO * 2, INICIO_POPULARIDAD_Y, renderizador,
                              &numeros[popularidad % 10]);
}

void RenderizadorServidorGrafico::renderizarNivelVacio() {
    texturaLetras.renderizar(INICIO_LETRAS_X, INICIO_NIVEL_Y, renderizador, &letras[26]);
    texturaLetras.renderizar(INICIO_LETRAS_X + LETRA_ANCHO, INICIO_NIVEL_Y, renderizador, &letras[26]);
    texturaLetras.renderizar(INICIO_LETRAS_X + LETRA_ANCHO * 2, INICIO_NIVEL_Y, renderizador, &letras[26]);
}

void RenderizadorServidorGrafico::renderizarNivel(Nat nivel) {
    texturaNumeros.renderizar(INICIO_LETRAS_X, INICIO_NIVEL_Y, renderizador, &numeros[nivel / 100 % 10]);
    texturaNumeros.renderizar(INICIO_LETRAS_X + LETRA_ANCHO, INICIO_NIVEL_Y, renderizador, &numeros[nivel / 10 % 10]);
    texturaNumeros.renderizar(INICIO_LETRAS_X + LETRA_ANCHO * 2, INICIO_NIVEL_Y, renderizador, &numeros[nivel % 10]);
}
