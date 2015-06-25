/*
A test game engine with C++ and OpenGL
Copyright (C) 2015  Sadman Kazi

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#include "input.h"
#include <stdlib.h>

std::vector<SDL_Keycode> Input::currentKeys(0);
std::vector<SDL_Keycode> Input::downKeys(0);
std::vector<SDL_Keycode> Input::upKeys(0);

void Input::update(SDL_Event* e) {
	Input::downKeys.clear();
	Input::upKeys.clear();
	if (e != NULL) {
		std::vector<SDL_Keycode>::iterator index;

		switch (e->type) {
		case SDL_KEYDOWN:
			//add the key to downkeys
			if (std::find(Input::currentKeys.begin(), Input::currentKeys.end(), e->key.keysym.sym) == Input::currentKeys.end()) {
				Input::downKeys.push_back(e->key.keysym.sym);
				//add it to current keys as well
				Input::currentKeys.push_back(e->key.keysym.sym);
			}
			break;

		case SDL_KEYUP:
			if (std::find(Input::currentKeys.begin(), Input::currentKeys.end(), e->key.keysym.sym) != Input::currentKeys.end()) {
				//add the key to up keys
				Input::upKeys.push_back(e->key.keysym.sym);
				//remove it from current keys as well
				//first find and store the index of the found element
				index = std::find(Input::currentKeys.begin(), Input::currentKeys.end(), e->key.keysym.sym);
				if (index != Input::currentKeys.end()) {
					Input::currentKeys.erase(index);
				}
			}
			break;

		default:
			break;
		}
	}
}

bool Input::getKey(SDL_Keycode key) {
	return std::find(Input::currentKeys.begin(), Input::currentKeys.end(), key) != Input::currentKeys.end();
}

bool Input::getKeyDown(SDL_Keycode key) {
	return std::find(Input::downKeys.begin(), Input::downKeys.end(), key) != Input::downKeys.end();
}

bool Input::getKeyUp(SDL_Keycode key) {
	return std::find(Input::upKeys.begin(), Input::upKeys.end(), key) != Input::upKeys.end();
}
