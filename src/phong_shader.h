#ifndef PHONG_SHADER_H_
#define PHONG_SHADER_H_

#include "shader.h"
#include "directional_light.h"

class PhongShader : public Shader {
public:
    static PhongShader* getInstance();
    virtual void updateUniforms(const glm::mat4&, const glm::mat4&,
            const Material*, const glm::vec3&);
    void setUniformBaseLight(const std::string&, const BaseLight&);
    void setUniformDirectionalLight(const std::string&, const DirectionalLight&);
    static void setAmbientLight(const glm::vec3&);
    static void setDirectionalLight(const DirectionalLight&);

private:
    PhongShader();
    static const std::string PHONG_SHADER_FILE;
    static glm::vec3 m_ambient_light;
    static DirectionalLight m_dir_light;
};

#endif // PHONG_SHADER_H_
