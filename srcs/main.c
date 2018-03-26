/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/26 21:56:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

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
			SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

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


	float vertices[] = {-0.5, -0.5,   0.0, 0.5,   0.5, -0.5};
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

	glUseProgram(shader->m_program_id);
	while (!terminer)
	{
		SDL_WaitEvent(&evenements);
		if (evenements.window.event == SDL_WINDOWEVENT_CLOSE || evenements.key.keysym.sym == SDLK_ESCAPE)
			terminer = 1;
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
