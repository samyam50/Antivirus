#pragma once
#include "game_object.h"

class Bullet_Two : public Game_Object
{
public:
	Bullet_Two(std::string id);
	~Bullet_Two();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};