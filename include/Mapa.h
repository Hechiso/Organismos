#pragma once
#include <vector>
#include"Tile.h"

class Mapa{
	private:
		int ancho,alto;
		std::vector<std::vector<Tile>> tiles;
	
	public:
		Mapa(int ancho,int alto) : ancho(ancho),alto(alto){
			tiles.resize(alto,std::vector<Tile>(ancho));
		}

		Tile& obtenerTile(int x,int y){
			return tiles[y][x];
		}

		bool PosicionValida(int x,int y) const{
			return x >= 0 && y >=0 && x < ancho && y < alto;
		}

		int getAncho() const {return ancho;}
		int getAlto() const {return alto;}
};
