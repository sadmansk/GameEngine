#include "shader.h"
#include <iostream>
#include <fstream>

static void checkError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string load(const std::string& fileName);
static GLuint create(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName)
{
    m_program = glCreateProgram();
    m_shaders[0] = create(load(fileName + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = create(load(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for (unsigned int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(m_program, m_shaders[i]);

    glBindAttribLocation(m_program, 0, "position");

    glLinkProgram(m_program);
    checkError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

    glValidateProgram(m_program);
    checkError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");
}


Shader::~Shader()
{
    for (unsigned int i = 0; i < NUM_SHADERS; i++) {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }

    glDeleteProgram(m_program);
}

void Shader::printActiveUniforms() {
    GLint i;
    GLint count;

    GLint size; // size of the variable
    GLenum type; // type of the variable (float, vec3 or mat4, etc)

    const GLsizei bufSize = 16; // maximum name length
    GLchar name[bufSize]; // variable name in GLSL
    GLsizei length; // name length

    glGetProgramiv(m_program, GL_ACTIVE_UNIFORMS, &count);
    std::cout << "Active Uniforms: " << count << std::endl;

    for (i = 0; i < count; i++) {
        glGetActiveUniform(m_program, (GLuint)i, bufSize, &length, &size, &type, name);
        std::cout << "Uniform #" << i << " Type: " << type << " Name: " << name << std::endl;
    }
}

void Shader::addUniform(const std::string& uniform) {
    int uniformLocation = glGetUniformLocation(m_program, uniform.c_str());

    if (uniformLocation == -1) {
        std::cerr << "Error: Could not find uniform " << uniform << std::endl;
        printActiveUniforms();
        throw std::exception(); // TODO: Custom exception class
    } else {
        //once we know that the uniform exists, add it to the hash map
        uniforms.insert({ uniform, uniformLocation });
    }
}

void Shader::setUniformI(const std::string& name, int value) {
    glUniform1i(uniforms.at(name), value);
}
void Shader::setUniformF(const std::string& name, float value) {
    glUniform1f(uniforms.at(name), value);
}

void Shader::setUniformMat4(const std::string& name, const glm::mat4& value) {
    glUniformMatrix4fv(uniforms.at(name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setUniformVec3(const std::string& name, const glm::vec3& value) {
    glUniform3f(uniforms.at(name), value.x, value.y, value.z);
}

void Shader::bind() {
    glUseProgram(m_program);
}

static GLuint create(const std::string& text, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);

    //error check
    if (shader == 0) //no shaders were given by openGL
        std::cerr << "Error: Shader creation failed!" << std::endl;

    const GLchar* shaderSourceStrings[1];
    GLint  shaderSourceStringLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();

    //get the source code and compile it
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);

    checkError(shader, GL_COMPILE_STATUS, false, "ERROR: Shader compilation failed!");

    return shader;
}

//loads the shader from a file, mostly for error checking
static std::string load(const std::string& fileName) {
    std::ifstream file;
    file.open(fileName.c_str());

    std::string output;
    std::string line;

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            output.append(line + "\n");
        }
    }

    else {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;

}

static void checkError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if (isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if (success == GL_FALSE)
    {
        if (isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}
