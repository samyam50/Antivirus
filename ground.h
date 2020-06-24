#pragma once
#include "game_object.h"

class Ground : public Game_Object
{
public:
	Ground(std::string id);
	~Ground();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
private:
	bool _has_spawned_another = false;
};