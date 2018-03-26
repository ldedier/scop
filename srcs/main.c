/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/27 01:31:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	ft_events(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
	{
		e->translate.y += 0.1;
	}
	else if (event.key.keysym.sym == SDLK_DOWN)
	{
		e->translate.y -= 0.1;
	}
	else if (event.key.keysym.sym == SDLK_RIGHT)
	{
		e->translate.x += 0.1;
	}
	else if (event.key.keysym.sym == SDLK_LEFT)
	{
		e->translate.x -= 0.1;
	}

	else if (event.key.keysym.sym == SDLK_p)
	{
		e->enhance.x += 0.1;
		e->enhance.y += 0.1;
	}
	else if (event.key.keysym.sym == SDLK_o)
	{
		e->enhance.x -= 0.1;
		e->enhance.y -= 0.1;
	}
}

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_env e;

	e.translate = ft_new_vec3(0,0,0);
	e.enhance = ft_new_vec3(1,1,1);

	SDL_Window* fenetre = NULL;
	SDL_GLContext contexteOpenGL = NULL;
	SDL_Event evenements;
	int terminer;
	terminer = 0;

/*
*/

//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
//	SDL_GL_CONTEXT_PROFILE_CORE);
//	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return (-1);
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
	SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (fenetre == 0)
	{
		SDL_Quit();
		return -1;
	}
	contexteOpenGL = SDL_GL_CreateContext(fenetre);
	if (contexteOpenGL == NULL)
	{
		ft_printf("inito\n");
		SDL_DestroyWindow(fenetre);
		return -1;
	}

	t_shader *shader = shd_new_shader("Shaders/basique2D.vert", "Shaders/basique2D.frag");
	if (!shd_charge(shader))
		ft_printf("pas bon\n");
	else
		ft_printf("content!\n");


	float vertices[] = {-0.5, -0.5,   0.0, 0.5, 0.5, -0.5};
	float colors[] = {
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0
	};

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	

	GLuint vbo[2];
	GLint location;
	glGenBuffers(2, vbo);
	
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);
	location = glGetAttribLocation(shader->m_program_id, "in_Vertex");
	glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, 0, NULL);	

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colors, GL_STATIC_DRAW);
	location = glGetAttribLocation(shader->m_program_id, "in_Colors");
	glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	t_mat4 translate_mat = ft_translate_mat(e.translate);
	t_mat4 enhance_mat = ft_enhance_mat(e.enhance);

	glUseProgram(shader->m_program_id);
	
	GLint loc_tr = glGetUniformLocation(shader->m_program_id, "Translate_mat");
	if (loc_tr != -1)
		glUniformMatrix4fv(loc_tr, 1, GL_FALSE, translate_mat);
	GLint loc_enhance = glGetUniformLocation(shader->m_program_id, "Enhance_mat");
	if (loc_enhance != -1)
		glUniformMatrix4fv(loc_enhance, 1, GL_FALSE, enhance_mat);
	while (!terminer)
	{
		while (SDL_PollEvent(&evenements)) {
			ft_events(&e, evenements);
			translate_mat = ft_translate_mat(e.translate);
			enhance_mat = ft_enhance_mat(e.enhance);
			
			glUniformMatrix4fv(loc_tr, 1, GL_FALSE, translate_mat);
			glUniformMatrix4fv(loc_enhance, 1, GL_FALSE, enhance_mat);
			if (evenements.window.event == SDL_WINDOWEVENT_CLOSE || evenements.key.keysym.sym == SDLK_ESCAPE)
				terminer = 1;
		}
		glClear(GL_COLOR_BUFFER_BIT);
   	 	glDrawArrays(GL_TRIANGLES, 0, 3);
		SDL_GL_SwapWindow(fenetre);
	}
	glUseProgram(0);
	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}
