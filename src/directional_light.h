#ifndef DIRECTIONAL_LIGHT_H_
#define DIRECTIONAL_LIGHT_H_

#include <glm/glm.hpp>
#include <iostream>

struct BaseLight {
    glm::vec3 color;
    float intensity;
    BaseLight(const glm::vec3& c, float i) :
        color(c), intensity(i) { }
};

struct DirectionalLight {
    BaseLight base;
    glm::vec3 dir;
    inline DirectionalLight(const BaseLight& b, const glm::vec3& d) :
        base(b), dir(glm::normalize(d)) {}
};


#endif // DIRECTIONAL_LIGHT_H_
