#include "basic_shader.h"

const std::string BasicShader::BASIC_SHADER_FILE = "../res/basicShader";

BasicShader* BasicShader::getInstance() {
    static BasicShader instance;
    return &instance;
}

BasicShader::BasicShader() :
    Shader(BASIC_SHADER_FILE) {

    addUniform("u_transform");
}

void BasicShader::updateUniforms(const glm::mat4& proj_matrix) {
    setUniformMat4("u_transform", proj_matrix);
}
