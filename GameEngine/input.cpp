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

Input::Input()
{
}

Input::~Input()
{
}

void Input::update(SDL_Event* e) {
	//translate the key status of the pressed into an into a SDL_Keysym
	SDL_Keysym keyEvent = e->key.keysym;

	//check whether the event is a key pressed down and then check whether its in the list of the current keys
	if (std::find(currentKeys.begin(), currentKeys.end(), keyEvent.sym) != currentKeys.end()) {

	}
}
bool Input::getKey(int keyCode) {
	return ;
}