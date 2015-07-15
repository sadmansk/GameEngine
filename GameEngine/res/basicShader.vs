#version 330

layout (location = 0) in vec3 position;

out vec4 color;

uniform mat4 transform;

void main () {
	gl_Position =  transform * vec4(position, 1.0);
	color = clamp(gl_Position, 0.0, 1.0);
}
