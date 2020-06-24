#include "ground.h"

Ground::Ground(std::string id)
	: Game_Object(id, "Texture.Ground")
{

	_translation = Vector_2D(50, 50);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}
Ground::~Ground()
{
}
void Ground::simulate_AI(Uint32, Assets*, Input*, Scene*scene)
{
	if (_translation.x() > 200.f && !_has_spawned_another)
	{
		scene->add_game_object(new Ground(id() + ".Next"));
			_has_spawned_another = true;
	}
	else if (_translation.x() > 400.f)
	{
		scene->add_game_object(new Ground(id() + ".Next"));
		_has_spawned_another = true;
	}
}