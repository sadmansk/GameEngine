#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "texture.h"
#include <glm/glm.hpp>

class Material {
public:
    Material(Texture*, glm::vec3*);
    const Texture* getTexture() const;
    void bindTexture(int index = 0) const;
    const glm::vec3* getColor() const;
    void setColor(const glm::vec3& color);
    const float getSpecIntensity() const;
    void setSpecIntensity(float value);
    const float getSpecPower() const;
    void setSpecPower(float value);
    virtual ~Material();

private:
    Texture* m_texture;
    glm::vec3* m_color;
    float m_spec_intensity;
    float m_spec_power;
};

#endif // MATERIAL_H_
