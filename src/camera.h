#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/geometric.hpp> // glm::cross
#include "input.h"

#define SPEED 0.001f
#define MOUSE_ENABLED true

#define DEBUG_MOVEMENT false
#ifdef DEBUG_MOVEMENT
#include <iostream>
#endif //DEBUG_MOVEMENT

class Camera
{
public:
    Camera(const glm::f32vec3& pos, float fov, float aspect, float zNear, float zFar) : m_position(pos) {
        m_perspective = glm::perspective(fov, aspect, zNear, zFar);

        //assuming that the vertical axis is y
        m_forward = glm::f32vec3(0, 0, 1);
        m_up = glm::f32vec3(0, 1, 0);

        m_mouse_pos = Input::getMousePos();
    }

    inline glm::mat4 getViewProjection() const {
        return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
    }

    inline void input() {
        if (MOUSE_ENABLED) {
            // Check if the mouse moved
            glm::vec2 new_mouse_pos = Input::getMousePos();
            int delta_x = new_mouse_pos.x - m_mouse_pos.x;
            if (DEBUG_MOVEMENT) {
                std::cout << "Delta X: " << delta_x << std::endl;
            }
            m_forward.x = glm::cos((float)delta_x/100);
            m_forward.z = glm::sin((float)delta_x/100);
        }

        //moving the camera
        if (Input::getKey(SDLK_w)) {
            m_position += (SPEED * m_forward);
            if (DEBUG_MOVEMENT) {
                std::cout << "Pressed W" << std::endl;
            }
        }
        if (Input::getKey(SDLK_s)) {
            m_position -= (SPEED * m_forward);
            if (DEBUG_MOVEMENT) {
                std::cout << "Pressed S" << std::endl;
            }
        }
        if (Input::getKey(SDLK_a)) {
            m_position -= (SPEED * glm::cross(m_forward, m_up));
            if (DEBUG_MOVEMENT) {
                std::cout << "Pressed A" << std::endl;
            }
        }
        if (Input::getKey(SDLK_d)) {
            m_position += (SPEED * glm::cross(m_forward, m_up));
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

    inline glm::vec3 getPos() const {
        return m_position;
    }

    ~Camera() {};

private:
    glm::mat4 m_perspective;
    glm::f32vec3 m_position;
    glm::f32vec3 m_forward;
    glm::f32vec3 m_up;

    glm::vec2 m_mouse_pos;
};

#endif //CAMERA_H
