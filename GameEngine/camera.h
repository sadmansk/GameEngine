#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

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

#endif CAMERA_H_INCLUDED