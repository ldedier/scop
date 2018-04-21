/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:35:16 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/21 16:56:07 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_shader	*shd_new_shader(char *vertex_source, char *fragment_source)
{
	t_shader *res;

	res = malloc(sizeof(t_shader));
	res->m_vertex_id = 0;
	res->m_fragment_id = 0;
	res->m_program_id = 0;
	res->m_vertex_source = ft_strdup(vertex_source);
	res->m_fragment_source = ft_strdup(fragment_source);
	return (res);
}

int			shd_charge(t_shader *shader)
{
	// Destruction d'un �ventuel ancien Shader

	if (glIsShader(shader->m_vertex_id) == GL_TRUE)
		glDeleteShader(shader->m_vertex_id);
	if (glIsShader(shader->m_fragment_id) == GL_TRUE)
		glDeleteShader(shader->m_fragment_id);
	if (glIsProgram(shader->m_program_id) == GL_TRUE)
		glDeleteProgram(shader->m_program_id);

	// Compilation des shaders
	if (!shd_compile(&(shader->m_vertex_id), GL_VERTEX_SHADER, shader->m_vertex_source))
		return 0;
	if (!shd_compile(&(shader->m_fragment_id), GL_FRAGMENT_SHADER, shader->m_fragment_source))
		return 0;

	// Cr�ation du programme

	shader->m_program_id = glCreateProgram();

	// Association des shaders

	glAttachShader(shader->m_program_id, shader->m_vertex_id);
	glAttachShader(shader->m_program_id, shader->m_fragment_id);

	// Verrouillage des entr�es shader
/*
	glBindAttribLocation(shader->m_program_id, 0, "in_Vertex");
	glBindAttribLocation(shader->m_program_id, 1, "in_Color");
	glBindAttribLocation(shader->m_program_id, 2, "in_TexCoord0");
*/
	// Linkage du programme

	glLinkProgram(shader->m_program_id);

	// V�rification du linkage

	GLint erreurLink = 0;
	glGetProgramiv(shader->m_program_id, GL_LINK_STATUS, &erreurLink);

	// S'il y a eu une erreur

	if (erreurLink != GL_TRUE)
	{
		// R�cup�ration de la taille de l'erreur

		GLint tailleErreur = 0;
		glGetProgramiv(shader->m_program_id, GL_INFO_LOG_LENGTH, &tailleErreur);

		// Allocation de m�moire

		char *erreur = ft_strnew(tailleErreur + 1);
		// R�cup�ration de l'erreur

		glGetShaderInfoLog(shader->m_program_id, tailleErreur, &tailleErreur, erreur);
		erreur[tailleErreur] = '\0';
		// Affichage de l'erreur
		printf("erreur de linkage: %s\n", erreur);

		// Lib�ration de la m�moire et retour du bool�en false
		free(erreur);
		glDeleteProgram(shader->m_program_id);
		return 0;
	}
	// Sinon c'est que tout s'est bien pass�
	else
		return 1;
}

t_mmap	ft_map_file(char *fileName)
{
	t_mmap res;
	int fd;
	int size;
	struct stat s;
	
	fd = open (fileName, O_RDONLY);
    fstat (fd, &s);
	size = s.st_size;
	res.ptr = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	res.size = size;
	return (res);
}


int     shd_compile(GLuint *shader_id, GLenum type, char *filename)
{
	*shader_id = glCreateShader(type);
	t_mmap map;

	if (*shader_id == 0)
	{
		ft_printf("id = 0\n");
		return 0;
	}

	const GLchar* chaineCodeSource;

	map = ft_map_file(filename);
	chaineCodeSource = map.ptr;
	ft_putendl(chaineCodeSource);
	if (!chaineCodeSource)
		return 0;
	// Envoi du code source au shader


	ft_printf("code source:\n%s\n", chaineCodeSource);
	glShaderSource(*shader_id, 1, &chaineCodeSource, 0);
	munmap(map.ptr, map.size);

	// Compilation du shader

	glCompileShader(*shader_id);

	// V�rification de la compilation
	
	GLint erreurCompilation = 0;
	glGetShaderiv(*shader_id, GL_COMPILE_STATUS, &erreurCompilation);

	// S'il y a eu une erreur

	if (erreurCompilation != GL_TRUE)
	{
		// R�cup�ration de la taille de l'erreur
		GLint tailleErreur = 0;
		glGetShaderiv(*shader_id, GL_INFO_LOG_LENGTH, &tailleErreur);
		// Allocation de m�moire
		char *erreur = ft_strnew(tailleErreur + 1);
		// R�cup�ration de l'erreur
		glGetShaderInfoLog(*shader_id, tailleErreur, &tailleErreur, erreur);
		erreur[tailleErreur] = '\0';
		ft_printf("%s\n", erreur);
		// Lib�ration de la m�moire et retour du bool�en false
		free(erreur);
		glDeleteShader(*shader_id);
		return 0;
	}
	// Sinon c'est que tout s'est bien pass�
	else
		return 1;
}
