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

#include <iostream>
#include "coreEngine.h"

//main program
int main(int argc, char* argv[]) {
    CoreEngine game (TITLE, WIDTH, HEIGHT);

    if (argc == 1) {
        std::cerr << "Usage: ./GameEngine path_to_model_files file_name1 file_name2 ...)" << std::endl;

        for (int i = 1; i < argc; i++) {
            game.loadMesh (std::string(argv[0], argv[i]));
        }
    }
    //main loop
    game.start();

    return 0;
}
