#include "assets.h"
#include "texture.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>
#include "game_object.h"

Assets::Assets(SDL_Renderer* renderer)
{

	// adding the floor
	{
		Texture* texture = new Texture("Texture.Ground", "Assets/virus.background.png", renderer);
		_assets[texture->id()] = texture;
	}

	//adding bullet texture

	{
		Texture* texture = new Texture("Texture.Virus.Bullet", "Assets/virus.bullet.png", renderer);
		_assets[texture->id()] = texture;
	}

	{
		Texture* texture = new Texture("Texture.Virus.Bullet.Two", "Assets/virus.bullet.two.png", renderer);
		_assets[texture->id()] = texture;
	}
	 
	{
		Texture* texture = new Texture("Texture.Virus.Bullet.Three", "Assets/virus.bullet.three.png", renderer);
		_assets[texture->id()] = texture;
	}

	{
		Texture* texture = new Texture("Texture.Virus.Tile.One", "Assets/Tiles_1.png", renderer);
		_assets[texture->id()] = texture;
	}
	{
		Texture* texture = new Texture("Texture.Virus.Tile.Two", "Assets/Tiles_2.png", renderer);
		_assets[texture->id()] = texture;
	}

	{
		Texture* texture = new Texture("Texture.Virus.Tile.Three", "Assets/Tiles_3.png", renderer);
		_assets[texture->id()] = texture;
	}
	{
		Texture* texture = new Texture("Texture.Virus.Tile.Four", "Assets/Tiles_4.png", renderer);
		_assets[texture->id()] = texture;
	}
	{
		Texture* texture = new Texture("Texture.Virus.Tile.Five", "Assets/Tiles_5.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Added player walking texture.
	{
		const int frame_count = 7;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Walking","Assets/player.walking.png", renderer, frame_count, frame_duration_milliseconds, false);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Added player flying texture.
	{
		const int frame_count = 6;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Flying", "Assets/player.flying.png", renderer, frame_count, frame_duration_milliseconds, false);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Added new  player running texture.
	{
		const int frame_count = 7;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Running", "Assets/player.running.png", renderer, frame_count, frame_duration_milliseconds, false);
		_assets[player_animated_texture->id()] = player_animated_texture;
		
	}

	// Added new player idle texture.
	{
		const int frame_count = 13;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Idle", "Assets/player.idle.png", renderer, frame_count, frame_duration_milliseconds, false);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}
	
	// Added new virus idle texture.
	{
		const int frame_count = 6;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Virus.Idle", "Assets/virus.idle.png", renderer, frame_count, frame_duration_milliseconds, false);
		_assets[animated_texture->id()] = animated_texture;
	}
	
	
	
	// Added new virus2 idle texture.
	{
		const int frame_count = 6;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Virus.Two.Idle", "Assets/virus.two.idle.png", renderer, frame_count, frame_duration_milliseconds, false);
		_assets[animated_texture->id()] = animated_texture;
	}
	

	// Added new virus3 idle texture.
	{
		const int frame_count = 7;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Virus.Three.Idle", "Assets/virus.three.idle.png", renderer, frame_count, frame_duration_milliseconds, true);
		_assets[animated_texture->id()] = animated_texture;
	}

	// Added new source idle texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Virus.Source", "Assets/virus.source.png", renderer, frame_count, frame_duration_milliseconds, true);
		_assets[animated_texture->id()] = animated_texture;
	}
	
	
	
	//collider
	
	{
		Texture* texture = new Texture("Texture.Collider", "Assets/collider.png", renderer);
		_assets[texture->id()] = texture;
	}

	// ADDED music sound
	{
		Sound* sound = new Sound("Sound.Music", "Assets/theme.wav");
		_assets[sound->id()] = sound;

		Mix_PlayChannel(0, sound->data(), -1);
	}

	
	{
		Sound* sound = new Sound("Sound.Walking", "Assets/walk.wav");
		_assets[sound->id()] = sound;
	}

	
	{
		Sound* sound = new Sound("Sound.Running", "Assets/running.wav");
		_assets[sound->id()] = sound;
	}


}

	Assets::~Assets()
{
	

}

Asset* Assets::get_asset(std::string id)
{
	if(_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets[id];
}