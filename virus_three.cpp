#include "virus_three.h"
#include "Projectile3.h"
#include <ctime>

Virus_Three::Virus_Three(std::string id)
	: Game_Object(id, "Texture.Virus.Three.Idle"),
	_generator(1337)
{

	_translation = Vector_2D( 1600 - 1000, 400 - 100);
	//_velocity = Vector_2D(0.0f, 0);

	_change_direction_timer = 0;

	_time_until_spawn_projectile = 2000;
}
Virus_Three::~Virus_Three()
{
}

void Virus_Three::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void Virus_Three::simulate_AI(Uint32 milliseconds_to_simulate, Assets*, Input*, Scene* scene)
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
		Projectile3* projectile3 = new Projectile3("Projectile3.Time." + std::to_string(time(0)));
		Game_Object* player = scene->get_game_object("Player");

		Vector_2D this_to_player = player->translation() - _translation;
		this_to_player.normalize();
		this_to_player.scale(0.25);

		projectile3->set_translation(_translation);
		projectile3->set_velocity(this_to_player);

		scene->add_game_object(projectile3);

		_time_until_spawn_projectile = 2000;
	}
}
