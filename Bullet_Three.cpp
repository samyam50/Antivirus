#pragma once
#include "Bullet_Three.h"

Bullet_Three::Bullet_Three(std::string id)
	: Game_Object(id, "Texture.Virus.Bullet.Three")
{

	_translation = Vector_2D(50, 50);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}
Bullet_Three::~Bullet_Three()
{
}
void Bullet_Three::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}