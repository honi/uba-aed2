#ifndef RENDERIZADORSERVIDORGRAFICO_H
#define RENDERIZADORSERVIDORGRAFICO_H

#include <SDL2/SDL.h>
#include "ServidorGrafico.h"
#include "Textura.h"

const int COMIENZO_MAPA_X = 225;
const int COMIENZO_MAPA_Y = 525;
const int VENTANA_ANCHO = 800;
const int VENTANA_ALTO = 600;
const int INICIO_MAS_UNIR_X = 380;
const int INICIO_MAS_ABRIR_X = 634;
const int INICIO_MAS_Y = 230;
const int MAS_ANCHO = 39;
const int MAS_ALTO = 39;
const int FILA_ALTO = 50;
const int SPRITE_ANCHO = 50;
const int SPRITE_ALTO = 50;
const int LETRA_ANCHO = 36;
const int LETRA_ALTO = 36;
const int INICIO_NOMBRES_X = 75;
const int INICIO_NOMBRES_Y = 239;
const int INICIO_BOTON_X = 7;
const int BOTON_ANCHO = 186;
const int INICIO_BOTON_CASA_Y = 361;
const int INICIO_BOTON_COMERCIO_Y = 426;
const int INICIO_BOTON_AVANZAR_Y = 491;
const int INICIO_BOTON_VOLVER_Y = 556;
const int BOTONES_ALTO = 60;
const int BOTON_VOLVER_ALTO = 39;
const int INICIO_BOTON_INICIAL_X = 307;
const int INICIO_BOTON_INICIAL_Y = 100;
const int INICIO_MAPA_X = 225;
const int FIN_MAPA_X = 775;
const int INICIO_MAPA_Y = 25;
const int FIN_MAPA_Y = 575;
const int INICIO_LETRAS_X = 46;
const int INICIO_NOMBRE_Y = 85;
const int INICIO_ANTIGUEDAD_Y = 160;
const int INICIO_POPULARIDAD_Y = 235;
const int INICIO_NIVEL_Y = 310;

// Renderizador de la ventana
extern SDL_Renderer *renderizador;

extern SDL_Rect sprites[40];
extern SDL_Rect numeros[10];
extern SDL_Rect letras[27];
extern SDL_Rect botones[6];
extern SDL_Rect mas[2];
extern SDL_Rect pantallaInicial;
extern SDL_Rect pantallaPrincipal;
extern Textura texturaSprites;
extern Textura texturaNumeros;
extern Textura texturaLetras;
extern Textura texturaBotones;
extern Textura texturaMas;
extern Textura texturaPantallaInicial;
extern Textura texturaPantallaPrincipal;

class RenderizadorServidorGrafico {
public:

    RenderizadorServidorGrafico(ServidorGrafico &sg);

    void mostrarPantallaInicial();

    void empezarNombrarPartida();

    void nombrarPartida(int indice);

    Nat cantidadJugadores() const;

    void empezarUnion(int indice);

    void unir(int indice);

    void abrirPartida(int indice);

    void empezarAgregarCasa();

    void agregarCasa(Casilla c);

    void empezarAgregarComercio();

    void agregarComercio(Casilla c);

    void mostrarNivel(Casilla c);

    void desplazarCentro(DireccionMovimiento direccion);

    void avanzarTurno();

    void cerrarPartida();

private:

    void nuevaPartida(Jugador j);

    void renderizarPantallaInicial();

    void renderizarListaPartidas();

    void renderizarMapaCompleto();

    void renderizarPosicion(int x, int y, TipoPosicion tp, bool seleccionado);

    void renderizarNombreActual();

    void renderizarAntiguedad();

    void renderizarPopularidad();

    void renderizarNivelVacio();

    void renderizarNivel(Nat nivel);

    ServidorGrafico _servidorGrafico;
    Nat _partidaUnir;
    Nat _cantidadJugadores;
    Jugador _nuevoJugador;
};

#endif // RENDERIZADORSERVIDORGRAFICO_H
