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
	inline Input() {};

	static void update(SDL_Event* e); //update the list of keys
	static bool getKey(SDL_Keycode key); //check whether a specific key is pressed
	static bool getKeyDown(SDL_Keycode key);
	static bool getKeyUp(SDL_Keycode key);
	static bool getMouse(Uint8 button); //check whether a specific key is pressed
	static bool getMouseDown(Uint8 button);
	static bool getMouseUp(Uint8 button);
	
	virtual ~Input() {};

private:
	static std::vector<SDL_Keycode> currentKeys; //store the keys pressed down
	static std::vector<SDL_Keycode> downKeys; //store the keys pressed in the current frame
	static std::vector<SDL_Keycode> upKeys; //store the keys released in the current frame
	static std::vector<Uint8> currentMouse; //store the mouse buttons pressed down
	static std::vector<Uint8> downMouse; //store the mouse buttons in the current frame
	static std::vector<Uint8> upMouse; //store the mouse buttons released in the current frame
};

