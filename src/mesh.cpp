#include "mesh.h"
#include <vector>

Mesh::Mesh(const std::string& fileName) {
    IndexedModel model = OBJModel(fileName).ToIndexedModel();
    InitMesh(model);
}

Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices)
{
    m_drawCount = numVertices; //binding the vertex array object
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);
    Mesh::calcNormals(vertices, numVertices, indices, numIndices);

    // retrieve the data from the vertices
    std::vector<glm::vec3*> posCoords;
    std::vector<glm::vec2*> texCoords;
    std::vector<glm::vec3*> normals;

    posCoords.reserve(numVertices);
    texCoords.reserve(numVertices);
    normals.reserve(numVertices);

    for (unsigned int i = 0; i < numVertices; i++) {
        posCoords.push_back(vertices[i].getPos());
        texCoords.push_back(vertices[i].getTexCoord());
        normals.push_back(vertices[i].getNormal());

    }

    //writing it to the GPU using buffers
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(posCoords[0]), &posCoords[0], GL_STATIC_DRAW);

    //assigning the data a location in the GPU memory
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(indices[0]), indices, GL_STATIC_DRAW);
    /*

    //glEnableVertexAttribArray(1);
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(1); //unbind the ARRAY from the GL handler
    */
    glBindVertexArray(0);

    //writing it to the GPU using buffers
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

    //assigning the data a location in the GPU memory
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(1);

}

void Mesh::draw() {
    glBindVertexArray(m_vertexArrayObject);

    //glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::InitMesh(const IndexedModel& model) {
    m_drawCount = model.positions.size();

    //binding the vertex array object
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    //writing it to the GPU using buffers
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW);

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

void Mesh::calcNormals(Vertex* vertices, unsigned int vertSize, unsigned int* indices, unsigned int indexSize) {
    for(int i = 0; i < indexSize; i += 3) {
        int i0 = indices[i];
        int i1 = indices[i + 1];
        int i2 = indices[i + 2];

        glm::vec3 v1 = *vertices[i1].getPos() - *vertices[i0].getPos();
        glm::vec3 v2 = *vertices[i2].getPos() - *vertices[i0].getPos();

        glm::vec3 normal = glm::normalize(glm::cross(v1, v2));

        *vertices[i0].getNormal() = *vertices[i0].getNormal() + normal;
        *vertices[i1].getNormal() = *vertices[i1].getNormal() + normal;
        *vertices[i2].getNormal() = *vertices[i2].getNormal() + normal;
    }

    for(int i = 0; i < vertSize; i++)
        *vertices[i].getNormal() = glm::normalize(*vertices[i].getNormal());
}
