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
    virtual ~Material();

private:
    Texture* m_texture;
    glm::vec3* m_color;
};

#endif // MATERIAL_H_
