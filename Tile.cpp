#pragma once

#include "Tile.h"

Tile::Tile(std::string id, std::string texture_id, Vector_2D translation, int scale)
	: Game_Object(id, texture_id)
{
	_translation = translation;
	_width = scale;
	_height = scale;
}

Tile::~Tile()
{
}

void Tile::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}