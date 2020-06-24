#include "input.h"
#include "resource.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_syswm.h>
#include <iostream>



Input::Input()
{
}
Input::~Input()
{
}

void Input::get_input()
{
	_button_state[Button::INCREASE_SPEED] = Button_State::UP;
	_button_state[Button::DECREASE_SPEED] = Button_State::UP;
	_button_state[Button::SHOW_CREDITS]   = Button_State::UP;
	_button_state[Button::DEBUG_SHOW_IDS] = Button_State::UP;

	for(auto button_state : _button_state)
	{
		if(button_state.second == Button_State::PRESSED)
		{
			_button_state[button_state.first] = Button_State::DOWN;
		}
		else if(button_state.second == Button_State::RELEASED)
		{
			_button_state[button_state.first] = Button_State::UP;
		}
	}

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			_button_state[Button::QUIT] = Button_State::PRESSED;
			break;

		case SDL_SYSWMEVENT:
			if(event.syswm.msg->msg.win.wParam == ID_FILE_EXIT)
			{
				_button_state[Button::QUIT] = Button_State::PRESSED;
			}
			else if(event.syswm.msg->msg.win.wParam == ID_PLAYER_INCREASESPEED)
			{
				_button_state[Button::INCREASE_SPEED] = Button_State::PRESSED;
			}
			else if(event.syswm.msg->msg.win.wParam == ID_PLAYER_DECREASESPEED)
			{
				_button_state[Button::DECREASE_SPEED] = Button_State::PRESSED;
			}
			else if(event.syswm.msg->msg.win.wParam == ID_CREDITS_DEVELOPERS)
			{
				_button_state[Button::SHOW_CREDITS] = Button_State::PRESSED;
			}
			else if(event.syswm.msg->msg.win.wParam == ID_DEBUG_TOGGLEDISPLAYID)
			{
				_button_state[Button::DEBUG_SHOW_IDS] = Button_State::PRESSED;
			}
			break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.scancode)
			{
			case SDL_SCANCODE_ESCAPE:
				if (!is_button_state(Button::PAUSE, Button_State::DOWN))
				{
					_button_state[Button::PAUSE] = Button_State::PRESSED;
				}
				break;
			case SDL_SCANCODE_W:
				if(!is_button_state(Button::UP, Button_State::DOWN))
				{
					_button_state[Button::UP] = Button_State::PRESSED;
				}
				break;
			case SDL_SCANCODE_A:
				if(!is_button_state(Button::LEFT, Button_State::DOWN))
				{
					_button_state[Button::LEFT] = Button_State::PRESSED;
				}
				break;
			case SDL_SCANCODE_S:
				if(!is_button_state(Button::DOWN, Button_State::DOWN))
				{
					_button_state[Button::DOWN] = Button_State::PRESSED;
				}
				break;
			case SDL_SCANCODE_D:
				if(!is_button_state(Button::RIGHT, Button_State::DOWN))
				{
					_button_state[Button::RIGHT] = Button_State::PRESSED;
				}
				break;
			case SDL_SCANCODE_LSHIFT:
				if(!is_button_state(Button::RUNNING, Button_State::DOWN))
				{
					_button_state[Button::RUNNING] = Button_State::PRESSED;
				}
				break;
			case SDL_SCANCODE_SPACE:
				if (!is_button_state(Button::FLYING, Button_State::DOWN))
				{
					_button_state[Button::FLYING] = Button_State::PRESSED;
				}
				break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.scancode)
			{
			case SDL_SCANCODE_ESCAPE:
				_button_state[Button::PAUSE] = Button_State::RELEASED;
				break;

			case SDL_SCANCODE_W:
				_button_state[Button::UP] = Button_State::RELEASED;
				break;
			case SDL_SCANCODE_A:
				_button_state[Button::LEFT] = Button_State::RELEASED;
				break;
			case SDL_SCANCODE_S:
				_button_state[Button::DOWN] = Button_State::RELEASED;
				break;
			case SDL_SCANCODE_D:
				_button_state[Button::RIGHT] = Button_State::RELEASED;
				break;
			case SDL_SCANCODE_LSHIFT:
				_button_state[Button::RUNNING] = Button_State::RELEASED;
				break;
			case SDL_SCANCODE_SPACE:
				_button_state[Button::FLYING] = Button_State::RELEASED;
				break;
			}
			break;
		}
	}
}
bool Input::is_button_state(Button type, Button_State state)
{
	if(_button_state.find(type) == _button_state.end())
	{
		if(state == Button_State::UP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return _button_state.find(type)->second == state;
}