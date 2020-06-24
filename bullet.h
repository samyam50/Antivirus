#pragma once
#include "game_object.h"

class Bullet : public Game_Object
{
public:
	Bullet(std::string id);
	~Bullet();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};