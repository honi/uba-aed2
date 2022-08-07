#include "InterfazGrafica.h"

SDL_Window *ventana = nullptr;

bool iniciar() {
    bool success = true;

    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        success = false;
    } else {
        // Setear filtrado de texturas a lineal
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Advertencia: No se pudo habilitar el fitrado de texturas lineal\n");
        }

        // Crear ventana
        ventana = SDL_CreateWindow("SimCity", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, VENTANA_ANCHO,
                                   VENTANA_ALTO, SDL_WINDOW_SHOWN);
        if (ventana == nullptr) {
            printf("Error al crear la ventana: %s\n", SDL_GetError());
            success = false;
        } else {
            // Crear renderizador para la ventana
            renderizador = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
            if (renderizador == nullptr) {
                printf("Error al crear el renderizador: %s\n", SDL_GetError());
                success = false;
            } else {
                // Inicializar color de renderizador
                SDL_SetRenderDrawColor(renderizador, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }
    return success;
}

bool cargarArchivos() {
    bool success = true;

    // Cargar los sprites desde la imagen
    if (!texturaSprites.cargarDesdeArchivo("../gui/imagenes/sprites.bmp", renderizador)) {
        printf("Fallo al cargar los sprites\n");
        success = false;
    } else {
        int i = 0;
        for (int y = 0; y < SPRITE_ALTO * 5; y += SPRITE_ALTO) {
            for (int x = 0; x < SPRITE_ANCHO * 8; x += SPRITE_ANCHO) {
                sprites[i].x = x;
                sprites[i].y = y;
                sprites[i].w = SPRITE_ANCHO;
                sprites[i].h = SPRITE_ALTO;
                ++i;
            }
        }
    }

    // Cargar los numeros desde la imagen
    if (!texturaNumeros.cargarDesdeArchivo("../gui/imagenes/numeros.bmp", renderizador)) {
        printf("Fallo al cargar los numeros\n");
        success = false;
    } else {
        int i = 0;
        for (int x = 0; x < LETRA_ANCHO * 10; x += LETRA_ANCHO) {
            numeros[i].x = x;
            numeros[i].y = 0;
            numeros[i].w = LETRA_ANCHO;
            numeros[i].h = LETRA_ALTO;
            ++i;
        }
    }

    // Cargar las letras desde la imagen
    if (!texturaLetras.cargarDesdeArchivo("../gui/imagenes/letras.bmp", renderizador)) {
        printf("Fallo al cargar las letras\n");
        success = false;
    } else {
        int i = 0;
        for (int x = 0; x < LETRA_ANCHO * 27; x += LETRA_ANCHO) {
            letras[i].x = x;
            letras[i].y = 0;
            letras[i].w = LETRA_ANCHO;
            letras[i].h = LETRA_ALTO;
            ++i;
        }
    }

    // Cargar los botones desde la imagen
    if (!texturaBotones.cargarDesdeArchivo("../gui/imagenes/botones.bmp", renderizador)) {
        printf("Fallo al cargar los botones\n");
        success = false;
    } else {
        int i = 0;
        for (int y = 0; y < BOTONES_ALTO * 6; y += BOTONES_ALTO) {
            botones[i].x = 0;
            botones[i].y = y;
            botones[i].w = BOTON_ANCHO;
            botones[i].h = BOTONES_ALTO;
            ++i;
        }
    }

    // Cargar los mas desde la imagen
    if (!texturaMas.cargarDesdeArchivo("../gui/imagenes/mas.bmp", renderizador)) {
        printf("Fallo al cargar los mas\n");
        success = false;
    } else {
        int i = 0;
        for (int x = 0; x < MAS_ANCHO * 2; x += MAS_ANCHO) {
            mas[i].x = x;
            mas[i].y = 0;
            mas[i].w = MAS_ANCHO;
            mas[i].h = MAS_ALTO;
            ++i;
        }
    }

    // Cargar la pantallaInicial desde la imagen
    if (!texturaPantallaInicial.cargarDesdeArchivo("../gui/imagenes/pantallainicial.bmp", renderizador)) {
        printf("Fallo al cargar la pantallaInicial\n");
        success = false;
    } else {
        pantallaInicial.x = 0;
        pantallaInicial.y = 0;
        pantallaInicial.w = VENTANA_ANCHO;
        pantallaInicial.h = VENTANA_ALTO;
    }

    // Cargar la pantallaPrincipal desde la imagen
    if (!texturaPantallaPrincipal.cargarDesdeArchivo("../gui/imagenes/pantallaprincipal.bmp", renderizador)) {
        printf("Fallo al cargar la pantallaPrincipal\n");
        success = false;
    } else {
        pantallaPrincipal.x = 0;
        pantallaPrincipal.y = 0;
        pantallaPrincipal.w = VENTANA_ANCHO;
        pantallaPrincipal.h = VENTANA_ALTO;
    }

    return success;
}

void cerrar() {
    // Liberar las imagenes cargadas
    texturaSprites.liberar();
    texturaNumeros.liberar();
    texturaLetras.liberar();
    texturaBotones.liberar();
    texturaMas.liberar();
    texturaPantallaInicial.liberar();
    texturaPantallaPrincipal.liberar();

    // Destruir la ventana
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(ventana);
    ventana = nullptr;
    renderizador = nullptr;

    // Salir de los subsistemas de SDL
    SDL_Quit();
}
