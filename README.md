# 3D Game Engine [![build status](https://git.sadmansk.com/sadmansk/GameEngine/badges/master/build.svg)](https://git.sadmansk.com/sadmansk/GameEngine/commits/master)
A test game engine with C++ and OpenGL.

## Quick Start
You need the following libraries:
* `cmake`
* `SDL2`
* `GLEW`
* `ASSIMP`
* `GLM`

CMake recommends out of directory builds, so it's a smart idea to make a new directory
(I'm calling it `build`) and run the following command from there:
```
cmake ..
make
```

> Note: These instructions are for Mac and Linux, Windows/Visual Studio details
coming soon.

## Current Features
### Core Engine:
- Keyboard and mouse input mapping
- First person camera

### Rendering:
- Wavefront (.obj) file loading
- Vertex and Fragment shaders support
- Textures support
- Basic Lighting
- Phong lighting model
- Material support

## Roadmap
These features are planned to be included *very soon*.
- Dynamic shaders management
- Level import and export

The following features are ambitious, depending on whether I plan to move on to
writing the C Vulkan engine or not:
- Physics
- Animation
- Scripting

## Demo
![Level loading](res/demo/level.gif)
Loading in a complete level from a wavefront file. Also showcases the first person
camera.

![Texture support](res/demo/texture.gif)
Showcasing texture support.

![Phong Lighting](res/demo/phong.gif)
Phong lighting model.

## Documentation
Refer to the [wiki](https://github.com/sadmansk/GameEngine/wiki) for more information.
Also if you are interested in contributing, follow these [guidelines](https://github.com/sadmansk/GameEngine/wiki/Contributing-to-the-Wiki).

## License
```
A test game engine with C++ and OpenGL
Copyright (C) 2017  Sadman Kazi

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
```
See [LICENSE](https://raw.githubusercontent.com/sadmansk/GameEngine/master/LICENSE)
for more details.
