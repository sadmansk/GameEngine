#version 330

in vec2 texCoord0;
out vec4 fragColor;

uniform sampler2D u_diffuse;

void main () {
    fragColor = texture2D(u_diffuse, texCoord0.xy);
}
