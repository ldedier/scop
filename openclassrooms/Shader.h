#ifndef DEF_SHADER
#define DEF_SHADER


// Include Windows

#ifdef WIN32
#include <GL/glew.h>


// Include Mac

#elif __APPLE__
#define GL3_PROTOTYPES 1
#include <OpenGL/gl3.h>


// Include UNIX/Linux

#else
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>

#endif


// Includes communs

#include <iostream>
#include <string>
#include <fstream>


// Classe Shader

typedef struct	s_shader
{
    GLuint		m_vertexID;
    GLuint		m_fragmentID;
    GLuint		m_programID;
}				t_shader;

t_shader		*shd_new_shader();
t_shader		*shd_copy(t_shader *shader);
t_shader		*shd_shader_params(char *vertex_source, char *fragment_source);
int				shd_charge(t_shader *shader);
int				shd_compile(t_shader *shader);
Gluint			shd_getProgramID(t_shader *shader);

#endif
