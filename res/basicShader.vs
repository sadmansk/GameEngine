#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec2 texCoord0;

uniform mat4 u_transform;

void main () {
	gl_Position =  u_transform * vec4(1.5*position, 1.0);
    texCoord0 = texCoord;
}
