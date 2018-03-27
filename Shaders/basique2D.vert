// Version du GLSL

#version 410 core


// Entrée Shader

in vec2 in_Vertex;
in vec3 in_Colors;

uniform mat4 Translate_mat;
uniform mat4 Scale_mat;
uniform mat4 Rotate_mat;

out vec3 v_Colors;

// Fonction main

void main()
{
// Position finale du vertex
    gl_Position = Translate_mat * Scale_mat * Rotate_mat * vec4(in_Vertex,0.0, 1.0);
	v_Colors = in_Colors;
}
