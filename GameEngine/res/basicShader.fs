#version 120


void main () {
	gl_FragColor = vec4(1.0f, 0.0f, 0.0f, 0.0f);//texture2D (diffuse, texCoord0) * clamp(dot(-vec3(0, 0, 1), normal0), 0.0, 1.0);
}
