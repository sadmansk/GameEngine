#include <iostream>
#include "window.h"

#define WIDTH 1280
#define HEIGHT 700
#define TITLE "GameEngine"
int main(int argc, char* argv[]) {
	Window MainWindow (TITLE, WIDTH, HEIGHT);

	//main loop
	while (!MainWindow.isClosed()) {
		MainWindow.clear(1.0f, 1.0f, 1.0f, 1.0f);
		MainWindow.update();
	}

	return 0;

}