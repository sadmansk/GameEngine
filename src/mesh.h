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
#ifndef MESH_H
#define MESH_H

#include "vertex.h"
#include <GL/glew.h>
#include "obj_loader.h"

class Mesh
{
public:
    Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
    Mesh(const std::string& fileName);
    void draw();
    ~Mesh();

private:
    enum {
        POSITION_VB,
        INDEX_VB,

        NUM_BUFFERS
    };

    void InitMesh(const IndexedModel& model);

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount; //stores how big it is, how much we want to draw
};

#endif // MESH_H
