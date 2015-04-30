#include <string>
#include "window.h"

#define WIDTH 1280
#define HEIGHT 700
#define TITLE "Game Engine"

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

	void run();
	void render();
};

