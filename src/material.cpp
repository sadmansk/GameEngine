#include "material.h"

Material::Material(Texture* texture, glm::vec3* color) :
    m_texture(texture),
    m_color(color) {}

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

Material::~Material() {
    delete m_texture;
    delete m_color;
}
