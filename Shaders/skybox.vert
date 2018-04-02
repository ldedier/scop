// Version du GLSL

#version 410 core

// Entrée Shader

in vec3 in_Vertex_skybox;
in vec3 in_Colors_skybox;

uniform mat4 Translate_mat;
uniform mat4 Scale_mat;
uniform mat4 Rotate_mat;
uniform mat4 View_mat;
uniform mat4 Projection_mat;

out vec3 v_Colors;

// Fonction main

void main()
{
    gl_Position = Projection_mat * View_mat * Translate_mat * Rotate_mat * Scale_mat * vec4(in_Vertex_skybox, 1.0);
	v_Colors = in_Colors_skybox;
}
