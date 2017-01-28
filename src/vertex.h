#ifndef VERTEX_H_
#define VERTEX_H_

#include <glm/glm.hpp>

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord) :
        m_pos(pos),
        m_texCoord(texCoord) {}

    inline glm::vec3* getPos() { return &m_pos; }
    inline glm::vec2* getTexCoord() { return &m_texCoord; }
private:
    glm::vec3 m_pos;
    glm::vec2 m_texCoord;
};

#endif // VERTEX_H_
