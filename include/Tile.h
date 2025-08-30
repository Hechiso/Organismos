#pragma once
#include "TipoTerreno.h"

struct Tile{
	TipoTerreno tipo;
	bool ocupado=false;

	Tile() : tipo(TipoTerreno::Fluido), ocupado(false) {}
};
