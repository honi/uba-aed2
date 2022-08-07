#ifndef TEXTURA_H
#define TEXTURA_H

#include <SDL2/SDL.h>
#include <string>

using namespace std;

class Textura {
public:
    // Inicializar variables
    Textura();

    // Liberar memoria
    ~Textura();

    // Cargar imagen desde una ruta
    bool cargarDesdeArchivo(const string &ruta, SDL_Renderer *renderizador);

    // Liberar textura
    void liberar();

    // Renderizar textura en el lugar especificado
    void renderizar(int x, int y, SDL_Renderer *gRenderer, SDL_Rect *clip = nullptr);

private:
    SDL_Texture *_textura;
    int _ancho;
    int _alto;
};

#endif // TEXTURA_H
