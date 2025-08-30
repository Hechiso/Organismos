#include "../include/estrategiaInterfaz.h"
#include "../include/Mapa.h"
#include "../include/Entidad.h"
#include "../include/Tile.h"
void EstrategiaPixel::ejecutar(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); // Color morado neon

    for(int j = PixelesSobrantesX; j < ancho - PixelesSobrantesX; j++) {
        SDL_RenderDrawPoint(renderer, j, PuntoInicioY);
    }

    for(int i = PixelesSobrantesY; i < alto - PixelesSobrantesY; i++) {
        SDL_RenderDrawPoint(renderer, PuntoInicioX, i);
    }

    /*
    for(int i = PixelesSobrantesX; i < PixelesSobrantesX + medidaChunk; i++) {
        for(int j = 0; j < medidaChunk; j++) {
            if(j == 0 || j == medidaChunk - 1) {
                SDL_RenderDrawPoint(renderer, i, j);
            }
            if(i == PixelesSobrantesX || i == PixelesSobrantesX + medidaChunk - 1) {
                SDL_RenderDrawPoint(renderer, i, j);
            }
        }
    }
    */

    SDL_SetRenderDrawColor(renderer, 50, 255, 50, 255); // Color verde
}





void Texto(SDL_Renderer* render){
        
        TTF_Init();
        TTF_Font* font=TTF_OpenFont("/usr/share/fonts/truetype/liberation/LiberationSansNarrow-Italic.ttf", 24);

        if (!font){
        }

        SDL_Color color = {255, 25,0};
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Hola SDL", color);
        SDL_Texture* message = SDL_CreateTextureFromSurface(render, surfaceMessage);


        // Renderiza el mensaje en el renderer
        SDL_Rect messageRect; // Define un rectángulo para la posición y el tamaño del mensaje
        messageRect.x = 10;  // Posición X
        messageRect.y = 10;  // Posición Y
        messageRect.w = surfaceMessage->w;  // Ancho del mensaje
        messageRect.h = surfaceMessage->h;  // Alto del mensaje

        // Dibuja el mensaje en el renderer
        SDL_RenderCopy(render, message, NULL, &messageRect);
}



void EstrategiaMapa::ejecutar(SDL_Renderer* renderer){

    const int tileSize = 4;

Mapa map(1366 / 4, 736 / 4); // tamaño del mapa en tiles de 4px

// Crear una célula
map.obtenerTile(50, 50).ocupado = true;



    for (int y = 0; y < map.getAlto(); ++y) {
        for (int x = 0; x < map.getAncho(); ++x) {
            const Tile& tile = map.obtenerTile(x, y);

            if (tile.tipo == TipoTerreno::Fluido) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Azul
            }

            SDL_Rect rect = { x * tileSize, y * tileSize, tileSize, tileSize };
            SDL_RenderFillRect(renderer, &rect);
        }
    }

}


void dibujarEntidad(SDL_Renderer* renderer, const Entidad& e) {
    const int tileSize = 4;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanco

    SDL_Rect rect = { e.x * tileSize, e.y * tileSize, tileSize, tileSize };
    SDL_RenderFillRect(renderer, &rect);
}
