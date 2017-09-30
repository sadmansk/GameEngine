#include "phong_shader.h"

const std::string PhongShader::PHONG_SHADER_FILE = "../res/phongShader";
glm::vec3 PhongShader::m_ambient_light = glm::vec3(0.2f, 0.2f, 0.2f);
DirectionalLight PhongShader::m_dir_light = DirectionalLight(
        BaseLight(glm::vec3(1,1,1), 0.8f),
        glm::vec3(1,0,-1));

PhongShader* PhongShader::getInstance() {
    static PhongShader instance;
    return &instance;
}

PhongShader::PhongShader() :
    Shader(PHONG_SHADER_FILE) {

    addUniform("u_transform");
    addUniform("u_proj_transform");
    addUniform("u_base_color");
    addUniform("u_ambient_light");
    addUniform("u_dir_light.base.color");
    addUniform("u_dir_light.base.intensity");
    addUniform("u_dir_light.direction");
    addUniform("u_spec_intensity");
    addUniform("u_spec_power");
    addUniform("u_eye_pos");
}

void PhongShader::updateUniforms(const glm::mat4& world_matrix,
        const glm::mat4& proj_matrix,
        const Material* material,
        const glm::vec3& camera_pos) {

    if (material->getTexture()) {
        material->bindTexture();
    } else {
        Texture::unbindAll();
    }

    setUniformMat4("u_transform", world_matrix);
    setUniformMat4("u_proj_transform", proj_matrix);
    setUniformVec3("u_base_color", *material->getColor());
    setUniformVec3("u_ambient_light", PhongShader::m_ambient_light);
    setUniformDirectionalLight("u_dir_light", PhongShader::m_dir_light);
    setUniformF("u_spec_intensity", material->getSpecIntensity());
    setUniformF("u_spec_power", material->getSpecPower());
    setUniformVec3("u_eye_pos", camera_pos);
}

void PhongShader::setAmbientLight(const glm::vec3& amb_light) {
    PhongShader::m_ambient_light = amb_light;
}

void PhongShader::setDirectionalLight(const DirectionalLight& dir_light) {
    PhongShader::m_dir_light = dir_light;
}

void PhongShader::setUniformBaseLight(const std::string& name, const BaseLight& base) {
    setUniformVec3(name + ".color", base.color);
    setUniformI(name + ".intensity", base.intensity);
}

void PhongShader::setUniformDirectionalLight(const std::string& name, const DirectionalLight& dir_light) {
    setUniformBaseLight(name + ".base", dir_light.base);
    setUniformVec3(name + ".direction", dir_light.dir);
}
