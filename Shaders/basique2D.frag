// Version du GLSL

#version 410 core


// Sortie Shader
in	vec3 v_Colors;
out vec4 fragColor;

// Fonction main

void main()
{

// Couleur finale du pixel
fragColor = vec4(v_Colors, 0.0);
//fragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
