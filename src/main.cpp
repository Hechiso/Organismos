#include "../include/Ventana.h"
#include "../include/estrategiaInterfaz.h"
#include "../include/Variables.h"



int main(int argc, char* args[]) {



	InicializarVariables();//  (  mover la funcion  )
			       

	// Crear una ventana con valores predeterminados de ancho y alto
	VentanaSDL ventana1("Simulacion", false, ancho, alto, 0, 0);

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

