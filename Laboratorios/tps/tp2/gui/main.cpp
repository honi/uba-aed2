#include <SDL2/SDL.h>
#include "ManejadorDeEventos.h"

int main(int argc, char *args[]) {
    // Inicializar SDL y crear la ventana
    if (!iniciar()) {
        printf("Fallo al inicializar\n");
    } else {
        // Cargar las imagenes
        if (!cargarArchivos()) {
            printf("Fallo al cargar las imagenes\n");
        } else {
            bool quit = false;

            // Limpiar la pantalla
            SDL_SetRenderDrawColor(renderizador, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderizador);

            // Inicializar variables para mostrar el juego
            aed2_Servidor s;
            ServidorGrafico sg(s);
            RenderizadorServidorGrafico rsg(sg);
            ManejadorDeEventos mde(rsg);

            // Mientras el programa esta corriendo
            while (!quit) {
                // Manejar los eventos en la cola
                while (SDL_PollEvent(mde.evento()) != 0) {
                    if (mde.evento()->type == SDL_QUIT) {
                        quit = true;
                    } else {
                        mde.manejarEvento();
                    }
                }
            }
        }
    }

    // Liberar los recursos y cerrar SDL
    cerrar();

    return 0;
}
