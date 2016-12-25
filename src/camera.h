#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "input.h"

#define SPEED 0.001f

#define DEBUG_MOVEMENT false
#ifdef DEBUG_MOVEMENT
#include <iostream>
#endif //DEBUG_MOVEMENT

class Camera
{
public:
    Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) : m_position(pos) {
        m_perspective = glm::perspective(fov, aspect, zNear, zFar);

        //assuming that the vertical axis is y
        m_forward = glm::vec3(0, 0, 1);
        m_up = glm::vec3(0, 1, 0);
    }

    inline glm::mat4 getViewProjection() const {
        return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
    }

    inline void input() {
        //moving the camera
        if (Input::getKey(SDLK_w)) {
            m_position.z += SPEED;
            if (DEBUG_MOVEMENT) {
                std::cout << "Pressed W" << std::endl;
            }
        }
        if (Input::getKey(SDLK_s)) {
            m_position.z -= SPEED;
            if (DEBUG_MOVEMENT) {
                std::cout << "Pressed S" << std::endl;
            }
        }
        if (Input::getKey(SDLK_a)) {
            m_position.x += SPEED;
            if (DEBUG_MOVEMENT) {
                std::cout << "Pressed A" << std::endl;
            }
        }
        if (Input::getKey(SDLK_d)) {
            m_position.x -= SPEED;
            if (DEBUG_MOVEMENT) {
                std::cout << "Pressed D" << std::endl;
            }
        }
    }

    inline void rotate(float angle, glm::vec3& axis) {
        m_forward = glm::rotate(m_forward, angle, axis);
        m_up = glm::rotate(m_up, angle, axis);
    }

    inline void translate(glm::vec3& displacement) {
        m_position += displacement;
    }

    ~Camera() {};

private:
    glm::mat4 m_perspective;
    glm::vec3 m_position;
    glm::vec3 m_forward;
    glm::vec3 m_up;
};

#endif //CAMERA_H
