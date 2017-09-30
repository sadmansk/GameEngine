#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "material.h"

class Shader {
public:
    Shader(const std::string& fileName);

    void bind();
    void printActiveUniforms();
    void addUniform(const std::string& uniform);
    //methods for setting uniform values
    void setUniformI(const std::string& name, int value);
    void setUniformF(const std::string& name, float value);
    void setUniformVec3(const std::string& name, const glm::vec3& value);
    void setUniformMat4(const std::string& name, const glm::mat4& value);
    virtual void updateUniforms(const glm::mat4&, const glm::mat4&, const Material*, const glm::vec3&) = 0;
    virtual ~Shader();

private:
    static const unsigned int NUM_SHADERS = 2; //since we will only be using vertex and fragment shaders(for now)

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
    std::unordered_map<std::string, int> uniforms;//stores the variable name and location of GLSL uniforms
};

#endif // SHADER_H_
