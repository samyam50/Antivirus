#pragma once

#include "game_object.h"
#include <time.h>
#include <random>

class Virus_Three : public Game_Object
{
public:
	Virus_Three(std::string id);
	~Virus_Three();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene) override;

private:
	int _time_until_spawn_projectile;
	Animated_Texture* _texture;
	int _change_direction_timer;
	std::minstd_rand0 _generator;
};
