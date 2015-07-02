#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glew\glew.h>
#include "transform.h"
#include "camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();
	void Update(const Transform& transform, const Camera& camera);
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	enum {
		TRANSFORM_U, //for storing the transform uniform in GLSL

		NUM_UNIFORMS
	};

	GLuint m_program; //keeps track of the shader, uses to locate the shader
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

#endif //SHADER_H