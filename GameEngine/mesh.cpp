#include "mesh.h"


Mesh::Mesh(Vertex* vertices, unsigned int numVertices) 
{
	m_drawCount = numVertices;

	//binding the vertex array object
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	//writing it to the GPU using buffers
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

	//assigning the data a location in the GPU memory
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0); //unbind the ARRAY from the GL handler
}

void Mesh::draw() {
	glBindVertexArray(m_vertexArrayObject);

	glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}
