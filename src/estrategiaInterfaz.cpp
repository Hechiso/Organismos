#include "../include/estrategiaInterfaz.h"


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



