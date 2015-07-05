#include <glew/glew.h>
#include <string>

class Shader
{
public:
	Shader(const std::string fileName);

	void bind();

	~Shader();

private:
	static const unsigned int NUM_SHADERS = 2; //since we will only be using vertex and fragment shaders(for now)

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};

