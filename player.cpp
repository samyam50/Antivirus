#pragma once
#include "player.h"
#include "sound.h"
#include <iostream>
#include <SDL_mixer.h>

Player::Player(std::string id)
	: Game_Object(id, "Texture.Player.Idle")
{
	_speed = 0.1f;

	_current_run_timer_ms = 0;
	_next_run_time_ms = 0;

	_translation = Vector_2D(0, 0);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));

	_state.push(State::Idle);
}
Player::~Player()
{
}

void Player::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void Player::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene*)
{
	_next_run_time_ms -= milliseconds_to_simulate;
	_current_run_timer_ms -= milliseconds_to_simulate;

	switch(_state.top())
	{
		case State::Idle:
			if(input->is_button_state(Input::Button::RUNNING, Input::Button_State::DOWN) 
				&& _velocity.magnitude() > 0.0f
				&& _next_run_time_ms< 0)
			{
				push_state(State::Running, assets);
			}
			else if(_velocity.magnitude() > 0.0f)
			{
				push_state(State::Walking, assets);
			}
			break;
		case State::Walking:
			if(_velocity.magnitude() == 0.0f)
			{
				pop_state(assets);
			}
			else if(input->is_button_state(Input::Button::RUNNING, Input::Button_State::PRESSED)
				&& _next_run_time_ms<0)
			{
				push_state(State::Running, assets);
			}
			break;
		case State::Running:
			if(_current_run_timer_ms< 0)
			{
				pop_state(assets);
			}
			else if(input->is_button_state(Input::Button::RUNNING, Input::Button_State::RELEASED))
			{
				pop_state(assets);
			}
			break;
		case State::Flying:
			if (_velocity.magnitude() == 0.0f)
			{
				pop_state(assets);
			}
			else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::RELEASED))
			{
				pop_state(assets);
			}
			break;
	}

	_velocity = Vector_2D(0, 0);

	if(input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(1.0f, 0);
	}

	if(input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(-1.0f, 0);
	}

	if(input->is_button_state(Input::Button::UP, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, -1.0f);
	}

	if(input->is_button_state(Input::Button::DOWN, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, 1.0f);
	}

	_velocity.normalize();
	_velocity.scale(_speed);
}

void Player::set_speed(float speed)
{
	_speed = speed;
}
float Player::speed()
{
	return _speed;
}

void Player::push_state(State state, Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.push(state);
	handle_enter_state(_state.top(), assets);
}
void Player::pop_state(Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.pop();
	handle_enter_state(_state.top(), assets);
}

void Player::handle_enter_state(State state, Assets* assets)
{
	switch(state)
	{
		case State::Idle:
			_texture_id = "Texture.Player.Idle";
			break;
		case State::Walking:
		{
			_texture_id = "Texture.Player.Walking";
			_speed = 0.15f;
			const int walking_channel = 1;
			Sound* sound = (Sound*)assets->get_asset("Sound.Walking");
			Mix_PlayChannel(walking_channel, sound->data(), -1);
			break;
		}
		case State::Running:
		{
			_texture_id = "Texture.Player.Running";
			_speed = 0.3f;
			const int running_channel = 2;
			Sound* sound = (Sound*)assets->get_asset("Sound.Running");
			Mix_PlayChannel(running_channel, sound->data(), -1);

			Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
			texture->reset();

			_current_run_timer_ms = 3000;
			break;
		}
		case State::Flying:
		{
			_texture_id = "Texture.Player.Flying";
			_speed = 0.1f;
			const int running_channel = 2;
			Sound* sound = (Sound*)assets->get_asset("Sound.Running");
			Mix_PlayChannel(running_channel, sound->data(), -1);
			break;
		}
	}
}

void Player::handle_exit_state(State state, Assets*)
{
	switch(state)
	{
		case State::Idle:
			break;
		case State::Walking:
		{
			const int walking_channel = 1;
			Mix_HaltChannel(walking_channel);
			break;
		}
		case State::Running:
		{
			const int running_channel = 2;
			Mix_HaltChannel(running_channel);

			_next_run_time_ms = 5000;
			break;

		}
		case State::Flying:
		{
			const int flying_channel = 3;
			Mix_HaltChannel(flying_channel);
			break;

		}
	}
}