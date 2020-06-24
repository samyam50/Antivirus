#pragma once
#include "Bullet_Two.h"

Bullet_Two::Bullet_Two(std::string id)
	: Game_Object(id, "Texture.Virus.Bullet.Two")
{

	_translation = Vector_2D(50, 50);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}
Bullet_Two::~Bullet_Two()
{
}
void Bullet_Two::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}