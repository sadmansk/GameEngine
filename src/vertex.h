#ifndef VERTEX_H_
#define VERTEX_H_

#include <glm/glm.hpp>

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0, 0, 0)) :
        m_pos(pos),
        m_texCoord(texCoord),
        m_normal(normal) {}

    inline glm::vec3* getPos() { return &m_pos; }
    inline glm::vec2* getTexCoord() { return &m_texCoord; }
    inline glm::vec3* getNormal() { return &m_normal; }
private:
    glm::vec3 m_pos;
    glm::vec2 m_texCoord;
    glm::vec3 m_normal;
};

#endif // VERTEX_H_
