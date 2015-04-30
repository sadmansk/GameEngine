#include <iostream>
#include "window.h"

#define WIDTH 1280
#define HEIGHT 700
#define TITLE "GameEngine"



//main program
int main(int argc, char* argv[]) {
	Window MainWindow (TITLE, WIDTH, HEIGHT);

	//main loop
	MainWindow.start();

	return 0;
}