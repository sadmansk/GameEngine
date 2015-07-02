#include "mesh.h"
#include <vector>
#include "obj_loader.h"

Mesh::Mesh(const std::string& fileName) {
	IndexedModel model = OBJModel(fileName).ToIndexedModel();
	InitMesh(model);
}

Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices)
{
	IndexedModel model;

	for (int i = 0; i < numVertices; i++) {
		model.positions.push_back(*vertices[i].getPos());
		model.texCoords.push_back(*vertices[i].getTexCoord());
		model.normals.push_back(*vertices[i].getNormal());
	}


	for (int i = 0; i < numIndices; i++) {
		model.indices.push_back(indices[i]);
	}

	InitMesh(model);
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw() {
	glBindVertexArray(m_vertexArrayObject); //anything affecting a vertex array will affect this one

	glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

	glBindVertexArray(0); //unbind
}

void Mesh::InitMesh(const IndexedModel& model) {

	m_drawCount = model.positions.size();

	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject); //anything affecting a vertex array will affect this specific vertex array

	//for the positions
	//get some buffers to work with
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	//interprete the data as an array and bind it
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	//take data and put it in the buffer, from program to GPU memory
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW); //static draw means that the data is not gonna change

	//need a vertex attribute for every vertex member, tells where in the sequence to look at in the GPU memory
	glEnableVertexAttribArray(0); //look at it as an array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//for the texture coordinates
	//get some buffers to work with
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	//interprete the data as an array and bind it
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
	//take data and put it in the buffer, from program to GPU memory
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW); //static draw means that the data is not gonna change


	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL_VB]);
	//take data and put it in the buffer, from program to GPU memory
	glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(model.normals[0]), &model.normals[0], GL_STATIC_DRAW); //static draw means that the data is not gonna change

	//need a vertex attribute for every vertex member, tells where in the sequence to look at in the GPU memory
	glEnableVertexAttribArray(2); //look at it as an array
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//get some buffers to work with
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	//interprete the data as an array and bind it
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
	//take data and put it in the buffer, from program to GPU memory
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW); //static draw means that the data is not gonna change


	glBindVertexArray(0);
}