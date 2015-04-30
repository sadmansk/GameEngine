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