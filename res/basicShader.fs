#version 330

in vec2 texCoord0;
in vec3 normal0;
out vec4 fragColor;

uniform sampler2D u_diffuse;
uniform vec3 u_ambientLight;
uniform vec3 u_color;

void main () {
    vec4 totalLight = vec4(u_ambientLight, 1);
    vec4 textureColor = texture2D(u_diffuse, texCoord0.xy) * clamp(dot(-vec3(1,1,1), normal0), 0.2, 1.0);

    if (textureColor == vec4(0,0,0,0))
        fragColor = vec4(u_color, 1);
    else
        fragColor = textureColor * vec4(u_color, 1);
}
