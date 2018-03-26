// Version du GLSL

#version 410 core


// Entrée Shader

in vec3 in_Vertex;
in vec3 in_Colors;

out vec3 v_Colors;

// Fonction main

void main()
{
    // Position finale du vertex

    gl_Position = vec4(in_Vertex, 1.0);
	v_Colors = in_Colors;
}
