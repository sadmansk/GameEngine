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
#include <sdl/SDL.h> //required for getting the keyboard inputs
#include <vector>

class Input
{
public:
	Input();

	void update(SDL_Event* e); //update the list of keys
	bool getKey(int keyCode); //check whether a specific key is pressed
	
	virtual ~Input();

private:
	std::vector<SDL_Keycode> currentKeys; //store the keys pressed down in the current frame
	std::vector<SDL_Keycode> downKeys; //store the keys pressed down from the previous frame
};

