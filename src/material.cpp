#include "material.h"

Material::Material(Texture* texture, glm::vec3* color) :
    m_texture(texture),
    m_color(color) {
        m_spec_power = 32;
        m_spec_intensity = 2;
    }

const Texture* Material::getTexture() const {
    return m_texture;
}

void Material::bindTexture(int index) const {
    m_texture->bind(index);
}

const glm::vec3* Material::getColor() const {
    return m_color;
}

void Material::setColor(const glm::vec3& color) {
    if (m_color != nullptr) delete m_color;
    m_color = new glm::vec3(color);
}

const float Material::getSpecIntensity() const {
    return m_spec_intensity;
}

void Material::setSpecIntensity(float value) {
    m_spec_intensity = value;
}

const float Material::getSpecPower() const {
    return m_spec_power;
}

void Material::setSpecPower(float value) {
    m_spec_power = value;
}

Material::~Material() {
    delete m_texture;
    delete m_color;
}
