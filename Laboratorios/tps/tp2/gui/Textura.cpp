#include "Textura.h"

Textura::Textura() {
    _textura = nullptr;
    _ancho = 0;
    _alto = 0;
}

Textura::~Textura() {
    liberar();
}

bool Textura::cargarDesdeArchivo(const string &ruta, SDL_Renderer *renderizador) {
    // Liberar textura previa
    liberar();

    // La textura final
    SDL_Texture *nuevaTextura = nullptr;

    // Cargar imagen de una ruta especifica
    SDL_Surface *superficieCargada = SDL_LoadBMP(ruta.c_str());
    if (superficieCargada == nullptr) {
        printf("Error al cargar la imagen de %s: %s\n", ruta.c_str(), SDL_GetError());
    } else {
        SDL_SetColorKey(superficieCargada, SDL_TRUE, SDL_MapRGB(superficieCargada->format, 0, 0xFF, 0xFF));

        // Crear textura desde superficie
        nuevaTextura = SDL_CreateTextureFromSurface(renderizador, superficieCargada);
        if (nuevaTextura == nullptr) {
            printf("Error al crear textura de %s: %s\n", ruta.c_str(), SDL_GetError());
        } else {
            // Obtener dimensiones de la imagen
            _ancho = superficieCargada->w;
            _alto = superficieCargada->h;
        }

        // Liberar la superficie anterior
        SDL_FreeSurface(superficieCargada);
    }

    _textura = nuevaTextura;
    return _textura != nullptr;
}

void Textura::liberar() {
    // Liberar la textura
    if (_textura != nullptr) {
        SDL_DestroyTexture(_textura);
        _textura = nullptr;
        _ancho = 0;
        _alto = 0;
    }
}

void Textura::renderizar(int x, int y, SDL_Renderer *renderizador, SDL_Rect *clip) {
    // Definir espacio para renderizar
    SDL_Rect rectangulo = {x, y, _ancho, _alto};

    // Definir dimensiones
    if (clip != nullptr) {
        rectangulo.w = clip->w;
        rectangulo.h = clip->h;
    }

    // Renderizar a la pantalla
    SDL_RenderCopy(renderizador, _textura, clip, &rectangulo);
}
