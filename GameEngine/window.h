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

#include <string>
#include <sdl\SDL.h>
#include "input.h"

class Window
{
public:
	//ctor
	Window(const std::string title, int width, int height);
	
	//class functions
	static void clear(float r, float g, float b, float a);
	static void initGraphics();
	inline bool isClosed() { return m_isClosed;	}
	void update();

	//dtor
	virtual ~Window();

private:
	SDL_Window* m_window;
	SDL_GLContext m_context;
	bool m_isClosed;
};
