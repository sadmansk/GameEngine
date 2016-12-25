#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "camera.h"

class Transform
{
public:
    Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
        m_pos(pos),
        m_rot(rot),
        m_scale(scale) {}

    //getter for transform matrix, generally called model matrix
    inline glm::mat4 getModel() const {
        glm::mat4 posMatrix = glm::translate(m_pos);
        glm::mat4 scaleMatrix = glm::scale(m_scale);
        glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1, 0, 0));
        glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0, 1, 0));
        glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0, 0, 1));

        glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

        //scale first, then rotation and then position transform
        return posMatrix * rotMatrix * scaleMatrix;
    }

    inline glm::mat4 getProjectedModel(Camera* camera)  const {
        return camera->getViewProjection() * getModel();
    }

    //getters, returns by reference
    inline glm::vec3& getPos() { return m_pos; }
    inline glm::vec3& getRot() { return m_rot; }
    inline glm::vec3& getScale() { return m_scale; }

    //setters
    inline void setPos(const glm::vec3& pos) { m_pos = pos; }
    inline void setRot(const glm::vec3& rot) { m_rot = rot; }
    inline void setScale(const glm::vec3& scale) { m_scale = scale; }


    virtual ~Transform() {};

private:
    glm::vec3 m_pos, m_rot, m_scale; //m_ refers to member variables
};
#endif // TRANSFORM_H_
