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

#include "game.h"
#include "input.h"
#include <iostream>
#include "time.h"

Game::Game()
{
	Vertex data[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
		Vertex(glm::vec3(0, 0.5, 0)),
		Vertex(glm::vec3(0.5, -0.5, 0)),
		Vertex(glm::vec3(0, -0.5, 0.5))};
	
	unsigned int indices[] = {0, 1, 3,
							3, 1, 2,
							2, 1, 0,
							0, 2, 3};

	shader = new Shader("./res/basicShader");

	mesh = new Mesh(data, sizeof(data)/sizeof(data[0]), indices, sizeof(indices)/sizeof(indices[0]));

	transform = new Transform();

	shader->addUniform("transform");
	counter = 0;
}


Game::~Game()
{
	delete mesh;
	delete shader;
}

void Game::input() {
}

void Game::render() {
	shader->bind();
	mesh->draw();
	if (Input::getKeyDown(SDLK_UP)) {
		std::cout << "You have pressed up!" << std::endl;
	}
	else if (Input::getKeyUp(SDLK_UP)) {
		std::cout << "You have released up!" << std::endl;
	}

	if (Input::getMouseDown(SDL_BUTTON_LEFT)) {
		std::cout << "X: " << Input::getMousePos().x << " Y: " << Input::getMousePos().y << std::endl;
	}
	else if (Input::getMouseUp(SDL_BUTTON_LEFT)) {
		std::cout << "You released the left mouse button!" << std::endl;
	}
}

void Game::update() {
	counter += Time::getDelta();
	//std::cout << counter << std::endl;
	float sinCounter = sinf(counter);
	float absSinCounter = abs(sinCounter);

	transform->GetPos().x = sinCounter;
	transform->GetRot().y = sinCounter;
	transform->GetRot().z = sinCounter;

	shader->setUniformMat4("transform", transform->GetModel());
}