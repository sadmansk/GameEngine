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
#include "camera.h"

#define WIDTH 1280
#define HEIGHT 700
#define TITLE "Game Engine"
#define FRAME_CAP 5000.0f

class Game
{
public:
	Game();

	void input();
	void update();
	void render();

	virtual ~Game();

private:
	Mesh* m_mesh;
	Shader* m_shader;
	Transform* m_transform;
	Camera* m_camera;
	float m_counter;
};

