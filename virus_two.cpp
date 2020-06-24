#include "virus_two.h"
#include "Projectile2.h"
#include <ctime>

Virus_Two::Virus_Two(std::string id)
	: Game_Object(id, "Texture.Virus.Two.Idle"),
	_generator(1337)
{

	_translation = Vector_2D(2000 - 1200, 400 - 100);
	//_velocity = Vector_2D(0.0f, 0);

	_change_direction_timer = 0;

	_time_until_spawn_projectile = 2000;

}
Virus_Two::~Virus_Two()
{
}

void Virus_Two::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void Virus_Two::simulate_AI(Uint32 milliseconds_to_simulate, Assets*, Input*, Scene*scene)
{
	_change_direction_timer -= milliseconds_to_simulate;

	if (_change_direction_timer <= 0)
	{
		float random_x = ((float)_generator() / _generator.max()) * 2 - 1;
		float random_y = ((float)_generator() / _generator.max()) * 2 - 1;

		Vector_2D random_vector = Vector_2D(random_x, random_y);
		random_vector.normalize();
		random_vector.scale(0.02f);

		_velocity += random_vector;
		_velocity.normalize();
		_velocity.scale(0.02f);

		_change_direction_timer = 1000;
	}

	_time_until_spawn_projectile -= milliseconds_to_simulate;

	if (_time_until_spawn_projectile <= 0)
	{
		Projectile2* projectile2 = new Projectile2("Projectile2.Time." + std::to_string(time(0)));
		Game_Object* player = scene->get_game_object("Player");

		Vector_2D this_to_player = player->translation() - _translation;
		this_to_player.normalize();
		this_to_player.scale(0.25);

		projectile2->set_translation(_translation);
		projectile2->set_velocity(this_to_player);

		scene->add_game_object(projectile2);

		_time_until_spawn_projectile = 2000;
	}
}
