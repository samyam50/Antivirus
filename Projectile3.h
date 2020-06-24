#pragma once

#include "game_object.h"

class Projectile3 : public Game_Object
{
public:
	Projectile3(std::string id);
	~Projectile3();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
}; 
