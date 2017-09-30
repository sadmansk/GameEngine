#include "basic_shader.h"

const std::string BasicShader::BASIC_SHADER_FILE = "../res/basicShader";

BasicShader* BasicShader::getInstance() {
    static BasicShader instance;
    return &instance;
}

BasicShader::BasicShader() :
    Shader(BASIC_SHADER_FILE) {

    addUniform("u_transform");
    addUniform("u_color");
}

void BasicShader::updateUniforms(const glm::mat4& world_matrix,
        const glm::mat4& proj_matrix,
        const Material* material,
        const glm::vec3&) {

    if (material->getTexture()) {
        material->bindTexture();
    } else {
        Texture::unbindAll();
    }

    setUniformMat4("u_transform", proj_matrix);
    setUniformVec3("u_color", *material->getColor());
}
