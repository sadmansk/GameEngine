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

#include "coreEngine.h"

CoreEngine::CoreEngine(std::string title, int width, int height) : title(title), width(width), height(height)
{
	mainWindow = new Window(title, width, height);

	isRunning = true;
}


CoreEngine::~CoreEngine()
{
	delete mainWindow;
	delete clock;
}



void CoreEngine::start() {
	if (!isRunning)
		return;
	clock = new Time();
	run();
}

void CoreEngine::render() {
	mainWindow->clear(1.0f, 1.0f, 1.0f, 1.0f);
	mainWindow->update();
}

//game loop
void CoreEngine::run() {
	isRunning = true;

	long lastTime = clock->elapsed();
	while (isRunning) {
		if (mainWindow->isClosed())
			stop();
		render();
	}

}

void CoreEngine::stop() {
	isRunning = false;
}