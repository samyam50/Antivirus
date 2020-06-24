#include "game_scene.h"
#include "dino.h"
#include "walking_dino.h"
#include "player.h"
#include "portal_entry.h"
#include "portal_exit.h"
#include "virus.h"
#include "virus_two.h"
#include "virus_three.h"
#include "ground.h"

#include "Tile.h"

#include <random>
#include <time.h>

Game_Scene::Game_Scene()
	: Scene("Game")
{
	add_game_object(new Player("Player"));
	add_game_object(new Virus("Virus"));
	add_game_object(new Virus_Two("Virus.Two"));
	add_game_object(new Virus_Three("Virus.Three"));

	add_game_object(new Ground("Texture.Ground"));

	int seed = 1337;
	std::minstd_rand0 generator(seed);
	int tiles_x = 10;
	int tiles_y = 10;
	int tile_scale = 100;

	for (int y = 0; y < tiles_y; ++y)
	{
		for (int x = 0; x < tiles_x; ++x)
		{
			float random_number = (float)generator() / generator.max();
			std::string id = "Tile.X" + std::to_string(x) + ".Y." + std::to_string(y);
			std::string texture_id = "";

			if (random_number < 0.33f)
			{
				texture_id = "Texture.Virus.Tile.One";
			}
			else if (random_number < 0.66f)
			{
				texture_id = "Texture.Virus.Tile.Two";
			}
			else if (random_number < 1.f)
			{
				texture_id = "Texture.Virus.Tile.Three";
			}

			Tile* tile = new Tile(id, texture_id, Vector_2D((float)x * (float)tile_scale, (float)y * (float)tile_scale), tile_scale);
			_game_objects[tile->id()] = tile;
		}
	}

	_background_color.r = 0;
	_background_color.g = 0;
	_background_color.b = 0;
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*window)
{
	Game_Object* player = get_game_object("Player");

	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + player->translation();
}