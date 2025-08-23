#include "../include/Ventana.h"
#include "../include/estrategiaInterfaz.h"
#include "../include/Variables.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <X11/Xlib.h>


using namespace std;



void InicializarVariables(){

      Display* d = XOpenDisplay(NULL);
      Screen*  s = DefaultScreenOfDisplay(d);
      ancho = WidthOfScreen(s);
      alto = HeightOfScreen(s);
      XCloseDisplay(d);

int operacion=0;
operacion=ancho/medidaChunk;

int resultado=0;
resultado=operacion*medidaChunk;

int inicio=0;
PuntoInicioX=resultado/2;
cout<<"inicio x : "<<PuntoInicioX<<endl;

operacion=0;
operacion=ancho-resultado;

resultado=0;
resultado=operacion/2;

PixelesSobrantesX=resultado;
cout<<"Pixeles sobrantes en X :"<<PixelesSobrantesX<<endl;

//--------------------------------------------------------

operacion=0;
operacion=alto/medidaChunk;

resultado=0;
resultado=operacion*medidaChunk;

inicio=0;
PuntoInicioY=resultado/2;
cout<<"inicio y : "<<PuntoInicioY<<endl;

operacion=0;
operacion=alto-resultado;

resultado=0;
resultado=operacion/2;

PixelesSobrantesY=resultado;


cout<<"Pixeles sobrantes en Y :"<<PixelesSobrantesY<<endl;

//-------------------------------------------------------



}




int main(int argc, char* args[]) {

     InicializarVariables();
	// Crear una ventana con valores predeterminados de ancho y alto
    VentanaSDL ventana1("Ventana", true, ancho, alto, 0, 0);

    if (!ventana1.inicializar()) {
        // Tratar el error de inicialización
        return 1;
    }




    EstrategiaPixel estrategia;

    ventana1.setEstrategia(&estrategia);

    bool ejecutando = true;
    while (ejecutando) {
        ventana1.manejarEventos();
        // Realizar operaciones de renderizado adicionales si es necesario

        if (ventana1.estaCerrado()) {
            ejecutando = false;
        }




        estrategia.ejecutar(ventana1.getRenderer()); // Ejecutar la estrategia en cada ciclo




	ventana1.actualizar();
       
       	// Mantener la ventana medio segundo
        SDL_Delay(10);

    }


    ventana1.limpiar();

    return 0;
}

