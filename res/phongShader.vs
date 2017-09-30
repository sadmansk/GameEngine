#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

out vec2 texCoord0;
out vec3 normal0;
out vec3 worldPos0;

uniform mat4 u_transform;
uniform mat4 u_proj_transform;

void main () {
	gl_Position =  u_proj_transform * vec4(position, 1.0);
    texCoord0 = texCoord;
    normal0 = (u_transform * vec4(normal, 0.0)).xyz;
    worldPos0 = (u_transform * vec4(position, 1.0)).xyz;
}
