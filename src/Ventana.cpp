#include "Ventana.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

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

