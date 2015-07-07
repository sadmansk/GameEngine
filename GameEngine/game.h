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
#include "mesh.h"
#include "shader.h"
#include "transform.h"

class Game
{
public:
	Game();

	void input();
	void update();
	void render();

	virtual ~Game();

private:
	Mesh* mesh;
	Shader* shader;
	Transform* transform;
	float counter;
};

