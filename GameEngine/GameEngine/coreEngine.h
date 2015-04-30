#include <string>
#include "window.h"
#include "time.h"

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
	Time* clock;
	void run();
	void render();
};

