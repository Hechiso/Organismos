#ifndef VENTANA_H
#define VENTANA_H

#include <SDL2/SDL.h>
#include <string>
#include "estrategiaInterfaz.h"


class VentanaSDL {
public:
    VentanaSDL(const std::string& title, 
               bool fullscreen, 
	       int width = 1000, 
               int height = 600, 
               int posX = SDL_WINDOWPOS_CENTERED, 
               int posY = SDL_WINDOWPOS_CENTERED);

    bool inicializar();
    void cerrar();
    void manejarEventos();
    void actualizar();
    void limpiar();
    bool estaCerrado() const;
    void setEstrategia(EstrategiaInterfaz* estrategia);
    SDL_Renderer* getRenderer() const { return m_renderer; }

private:
    std::string m_title;
    int m_width;
    int m_height;
    int m_posX;
    int m_posY;
    bool m_fullscreen;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    bool m_cerrado = false;
    EstrategiaInterfaz* m_estrategia;
};

#endif

