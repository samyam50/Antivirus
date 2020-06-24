#pragma once

#include "game_object.h"

class Tile : public Game_Object
{
public:
	Tile(std::string id, std::string texture_id, Vector_2D translation, int scale);
	~Tile();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};