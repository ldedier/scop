// Version du GLSL

#version 410 core


// Sortie Shader

in	vec3 texCoords;

out vec4 fragColor;

uniform samplerCube skybox;

void main()
{
	fragColor = texture(skybox, texCoords);
}
