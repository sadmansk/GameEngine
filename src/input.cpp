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

#include "input.h"
#include <stdlib.h>
#include <algorithm>

std::vector<SDL_Keycode> Input::currentKeys(0);
std::vector<SDL_Keycode> Input::downKeys(0);
std::vector<SDL_Keycode> Input::upKeys(0);
std::vector<Uint8> Input::currentMouse(0); //store the mouse buttons pressed down
std::vector<Uint8> Input::downMouse(0); //store the mouse buttons in the current frame
std::vector<Uint8> Input::upMouse(0); //store the mouse buttons released in the current frame

template <typename T>
bool contains(std::vector<T> list, T item) {
    return std::find(list.begin(), list.end(), item) != list.end();
}

void Input::update(SDL_Event* e) {
    Input::downKeys.clear();
    Input::upKeys.clear();
    Input::downMouse.clear();
    Input::upMouse.clear();

    if (e != NULL) {
        std::vector<SDL_Keycode>::iterator index;
        std::vector<Uint8>::iterator mouseIndex;

        switch (e->type) {
            //handle mouse clicks
            case SDL_MOUSEBUTTONDOWN:
                if (!contains(currentMouse, e->button.button)) {
                    Input::downMouse.push_back(e->button.button);
                    Input::currentMouse.push_back(e->button.button);
                }
                break;

            case SDL_MOUSEBUTTONUP:
                if (contains(currentMouse, e->button.button)) {
                    mouseIndex = std::find(Input::currentMouse.begin(), Input::currentMouse.end(), e->button.button);
                    if (mouseIndex != Input::currentMouse.end()) {
                        Input::currentMouse.erase(mouseIndex);
                    }
                }
                Input::upMouse.push_back(e->button.button);
                break;

            case SDL_KEYDOWN:
                //add the key to downkeys
                if (!contains(currentKeys, e->key.keysym.sym)) {
                    Input::downKeys.push_back(e->key.keysym.sym);
                    //add it to current keys as well
                    Input::currentKeys.push_back(e->key.keysym.sym);
                }
                break;

            case SDL_KEYUP:
                if (contains(currentKeys, e->key.keysym.sym)) {
                    //remove it from current keys as well
                    //first find and store the index of the found element
                    index = std::find(Input::currentKeys.begin(), Input::currentKeys.end(), e->key.keysym.sym);
                    if (index != Input::currentKeys.end()) {
                        Input::currentKeys.erase(index);
                    }
                }
                //add the key to up keys
                Input::upKeys.push_back(e->key.keysym.sym);
                break;

            default:
                break;
        }
    }
}

bool Input::getKey(SDL_Keycode key) {
    return contains(currentKeys, key);
}

bool Input::getKeyDown(SDL_Keycode key) {
    return contains(downKeys, key);
}

bool Input::getKeyUp(SDL_Keycode key) {
    return contains(upKeys, key);
}

bool Input::getMouse(Uint8 button) {
    return contains(currentMouse, button);
}

bool Input::getMouseDown(Uint8 button) {
    return contains(downMouse, button);
}

bool Input::getMouseUp(Uint8 button) {
    return contains(upMouse, button);
}

glm::vec2 Input::getMousePos() { //TODO: might consider switching to a custom vector class
    int x, y;
    SDL_GetMouseState(&x, &y);
    return glm::vec2(x, y);
}
