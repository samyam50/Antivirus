#pragma once

#include "game_object.h"

class Projectile : public Game_Object
{
public:
	Projectile(std::string id);
	~Projectile();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};