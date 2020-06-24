#pragma once

#include "game_object.h"

class Projectile2 : public Game_Object
{
public:
	Projectile2(std::string id);
	~Projectile2();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};