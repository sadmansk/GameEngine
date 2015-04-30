#include <iostream>
#include "coreEngine.h"

//main program
int main(int argc, char* argv[]) {
	CoreEngine game (TITLE, WIDTH, HEIGHT);

	//main loop
	game.start();

	return 0;
}