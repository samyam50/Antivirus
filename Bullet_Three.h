#pragma once
#include "game_object.h"

class Bullet_Three : public Game_Object
{
public:
	Bullet_Three(std::string id);
	~Bullet_Three();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};
