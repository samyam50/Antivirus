#include "source.h"




Source::Source(std::string id)
	: Game_Object(id, "Texture.Virus.Source")
{

	_translation = Vector_2D(150, 150);
	//_velocity = Vector_2D(0.0f, 0);


}
Source::~Source()
{
}

void Source::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void Source::simulate_AI(Uint32, Assets*, Input*, Scene* )
{

	
}
