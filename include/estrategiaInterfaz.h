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
    	void ejecutar(SDL_Renderer* renderer);
};


void Texto(SDL_Renderer* render);
        

#endif
