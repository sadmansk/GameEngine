#version 330

in vec2 texCoord0;
in vec3 normal0;
out vec4 frag_color;

struct BaseLight {
    vec3 color;
    float intensity;
};

struct DirectionalLight {
    BaseLight base;
    vec3 direction;
};

uniform vec3 u_base_color;
uniform vec3 u_ambient_light;
uniform sampler2D u_sampler;
uniform DirectionalLight u_dir_light;

vec4 calcLight(BaseLight base, vec3 dir, vec3 normal) {
    float diffuseFactor = dot(normal, -dir);

    vec4 diffuseColor = vec4(1, 1, 1, 1);

    if (diffuseFactor > 0) {
        diffuseColor = vec4(base.color, 1.0) * base.intensity * diffuseFactor;
    }

    return diffuseColor;
}

vec4 calcDirectionalLight(DirectionalLight dir_light, vec3 normal) {
    return calcLight(dir_light.base, -dir_light.direction, normal);
}

void main() {
    vec4 total_light = vec4(u_ambient_light, 1);
    vec4 color = vec4(u_base_color, 1);
    vec4 texture_color = texture(u_sampler, texCoord0.xy);

    if (texture_color != vec4(0, 0, 0, 0)) {
        color *= texture_color;
    }

    vec3 normal = normalize(normal0);
    //total_light += calcDirectionalLight(u_dir_light, normal);
    total_light += calcLight(u_dir_light.base, u_dir_light.direction, normal);

    frag_color = color * total_light;
}


