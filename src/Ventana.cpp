#include "Ventana.h"
#include "Variables.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>



VentanaSDL::VentanaSDL(const std::string& title, bool fullscreen, int width, int height, int posX, int posY)
    : m_title(title), m_width(width), m_height(height), m_posX(posX), m_posY(posY), m_fullscreen(fullscreen), m_cerrado(false), m_estrategia(nullptr) {}

	bool VentanaSDL::inicializar() {
    	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        	return false;
   	}

    	int flags = 0;

	if (m_fullscreen) {
        	flags = SDL_WINDOW_FULLSCREEN;
    	}

    	m_window = SDL_CreateWindow(m_title.c_str(), m_posX, m_posY, m_width, m_height, flags);

	if (m_window == nullptr) {
	        return false;
   	}

    	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (m_renderer == nullptr) {
	        return false;
   	}

//----------------------------------------

	Texto(m_renderer);

//---------------------------------------
    	return true;
}



void VentanaSDL::cerrar() {
    m_cerrado = true;
}

void VentanaSDL::manejarEventos() {
    SDL_Event evento;
    while (SDL_PollEvent(&evento) != 0) {
        if (evento.type == SDL_QUIT) {
            cerrar();
        }
    }
}

void VentanaSDL::actualizar() {
    SDL_RenderPresent(m_renderer);
}

void VentanaSDL::limpiar() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool VentanaSDL::estaCerrado() const {
    return m_cerrado;
}

void VentanaSDL::setEstrategia(EstrategiaInterfaz* estrategia) {
    m_estrategia = estrategia;
}


void InicializarVariables(){

      Display* d = XOpenDisplay(NULL);
      Screen*  s = DefaultScreenOfDisplay(d);
      ancho = WidthOfScreen(s);
      alto = HeightOfScreen(s);
      XCloseDisplay(d);


//------------------------------- se obtiene las dineciones de la pantalla del dispositivo


        int operacion=0;
        int resultado=0;
        int inicio=0;

        PuntoInicioX=resultado/2;
	std::cout<<"inicio x : "<<PuntoInicioX<<std::endl;

        operacion=0;
        operacion=ancho-resultado;
        operacion=ancho/medidaChunk;
        resultado=operacion*medidaChunk;


        PuntoInicioX=resultado/2;
	std::cout<<"inicio x : "<<PuntoInicioX<<std::endl;

        operacion=0;
        operacion=ancho-resultado;

        resultado=0;
        resultado=operacion/2;

        PixelesSobrantesX=resultado;
	std::cout<<"Pixeles sobrantes en X :"<<PixelesSobrantesX<<std::endl;

//--------------------------------------------------------

        operacion=0;
        operacion=alto/medidaChunk;

        resultado=0;
        resultado=operacion*medidaChunk;

        inicio=0;
        PuntoInicioY=resultado/2;
	std::cout<<"inicio y : "<<PuntoInicioY<<std::endl;

        operacion=0;
        operacion=alto-resultado;

        resultado=0;
        resultado=operacion/2;

        PixelesSobrantesY=resultado;
	std::cout<<"Pixeles sobrantes en Y :"<<PixelesSobrantesY<<std::endl;


}

