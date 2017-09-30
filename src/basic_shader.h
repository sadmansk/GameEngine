#ifndef BASIC_SHADER_H_
#define BASIC_SHADER_H_

#include "shader.h"

class BasicShader : public Shader {
public:
    static BasicShader* getInstance();
    virtual void updateUniforms(const glm::mat4& world_matrix,
            const glm::mat4& proj_matrix,
            const Material* material,
            const glm::vec3&);

private:
    BasicShader();
    static const std::string BASIC_SHADER_FILE;
};

#endif // BASIC_SHADER_H_
