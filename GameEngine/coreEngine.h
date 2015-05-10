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
#include "window.h"
#include "time.h"
#include "game.h"

#define WIDTH 1280
#define HEIGHT 700
#define TITLE "Game Engine"
#define FRAME_CAP 5000.0f

class CoreEngine
{
public:
	CoreEngine(std::string title = TITLE, int width = WIDTH, int height = HEIGHT);

	void start();
	void stop();

	~CoreEngine();

private:
	Window* mainWindow;
	int width, height;
	const std::string title;
	bool isRunning;
	Game* game;

	void run();
	void render();
};

