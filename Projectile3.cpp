#pragma once

#include "Projectile3.h"
#include <iostream>

Projectile3::Projectile3(std::string id)
	: Game_Object(id, "Texture.Virus.Bullet.Three")
{
	_width = 100;
	_height = 100;

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}

Projectile3::~Projectile3() {};

void Projectile3::simulate_AI(Uint32, Assets*, Input*, Scene* scene)
{
	if (_translation.x() < -100.f || _translation.x() > 800.f || _translation.y() < -100.f || _translation.y() > 800.f)
	{
		scene->remove_game_object(id());
		std::cout << "Destroyed " << id() << std::endl;
	}
}
