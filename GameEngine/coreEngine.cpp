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
#include <windows.h>
#include <iostream>

CoreEngine::CoreEngine(std::string title, int width, int height) : title(title), width(width), height(height)
{
	mainWindow = new Window(title, width, height);
	game = new Game();

	isRunning = true;
}


CoreEngine::~CoreEngine()
{
	delete mainWindow;
	delete game;
}



void CoreEngine::start() {
	std::cout << "Core engine started." << std::endl;
	if (!isRunning) {
		std::cout << "Core engine closing." << std::endl;
		return;
	}

	Time::reset();
	run();
}

void CoreEngine::render() {
	mainWindow->clear(1.0f, 1.0f, 1.0f, 1.0f);
	mainWindow->update();
}

//game loop
void CoreEngine::run() {
	isRunning = true;
	std::cout << "Engine starting...";

	int frames = 0;
	long frameCounter = 0;

	double frameTime = 1.0 / FRAME_CAP;

	//lastTime before running the game loop
	long long lastTime = Time::elapsed();
	double unprocessedTime = 0;

	while (isRunning) {
		bool render = false;
		long long startTime = Time::elapsed();
		long long passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += (double)passedTime/SECOND; //store the time in seconds
		frameCounter += passedTime; //store the time in nanoseconds

		//update the time when the loop has run for frame time seconds
		while (unprocessedTime > frameTime) {
			render = true;
			unprocessedTime -= frameTime;

			if (mainWindow->isClosed())
				stop();

			Time::setDelta(frameTime);

			//update the game here
			game->input(); //process the inputs
			game->update(); //update game values

			//display the frame count every second
			if (frameCounter >= SECOND) {
				std::cout << frames << std::endl;
				frames = 0;
				frameCounter = 0;
			}
		}

		if (render) {
			this->render();
			game->render();
			frames++;
		}
		else
			Sleep(1); //delay the loop so that calculations are not made too often
	}

}

void CoreEngine::stop() {
	isRunning = false;
}