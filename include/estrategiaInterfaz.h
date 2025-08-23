#ifndef ESTRATEGIAINTERFAZ_H
#define ESTRATEGIAINTERFAZ_H

#include "Variables.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>



class EstrategiaInterfaz {
public:
    virtual void ejecutar(SDL_Renderer* renderer) = 0;
};

class EstrategiaPixel : public EstrategiaInterfaz {
public:
	int contador=0;
    	void ejecutar(SDL_Renderer* renderer) override {

//-------------------------------------------------------------------

	       	SDL_SetRenderDrawColor(renderer,255, 0, 255, 255); // Establecer el color en morado neon


for(int j=PixelesSobrantesX;j<ancho-PixelesSobrantesX;j++){		

       SDL_RenderDrawPoint(renderer,j,PuntoInicioY); // Dibujar un píxel rojo en la posición (100, 100)
       
}


for(int i=PixelesSobrantesY;i<alto-PixelesSobrantesY;i++){
  
  	SDL_RenderDrawPoint(renderer,PuntoInicioX,i); // Dibujar un píxel rojo en la posición (100, 100)

}



//int separacion=11;

for(int i=PixelesSobrantesX;i<PixelesSobrantesX+medidaChunk;i++){
	for(int j=0;j<medidaChunk;j++){
		if(j==0 || j==medidaChunk-1){
		SDL_RenderDrawPoint(renderer,i,j);
		}
		if(i==PixelesSobrantesX || i==PixelesSobrantesX+medidaChunk-1){
		SDL_RenderDrawPoint(renderer,i,j);	
		}
	}
}

//------------------------------------------------------------------

SDL_SetRenderDrawColor(renderer,50,255,50,255); // Establecer el color en morado neon
SDL_RenderDrawPoint(renderer,PuntoInicioX,PuntoInicioY);	
	
}


};

#endif

