// Version du GLSL

#version 410 core

// Entrée Shader

in vec3 in_Vertex_skybox;

uniform mat4 Translate_mat;
uniform mat4 View_mat;
uniform mat4 Projection_mat;

out vec3 texCoords;

// Fonction main

void main()
{
	texCoords = in_Vertex_skybox;
    gl_Position = Projection_mat * View_mat * Translate_mat * vec4(in_Vertex_skybox, 1.0);
}
