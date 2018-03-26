/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/26 03:56:40 by ldedier          ###   ########.fr       */
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
	terminer = 1;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
	SDL_GL_CONTEXT_PROFILE_CORE);
	terminer = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return (-1);
	}
	fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (fenetre == 0)
	{
		SDL_Quit();
		printf("inita\n");
		SDL_Quit();
		return -1;
	}
	contexteOpenGL = SDL_GL_CreateContext(fenetre);
	if (contexteOpenGL == NULL)
	{
		SDL_DestroyWindow(fenetre);
		return -1;
	}



	 float vertices[] = {0.0, 1.0, -0.5, 0.0, 0.5, 0.0, 0.0, -1.0};
	// Vertices

//float vertices[] = {0.0, 0.0,   0.5, 0.0,   0.0, 0.5,          // Triangle 1
//                   -0.8, -0.8,   -0.3, -0.8,   -0.8, -0.3};   // Triangle 2
	while(!terminer)
	{
		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glDisableVertexAttribArray(0);
		SDL_GL_SwapWindow(fenetre);
		SDL_WaitEvent(&evenements);
		if (evenements.window.event == SDL_WINDOWEVENT_CLOSE || evenements.key.keysym.sym == SDLK_ESCAPE)
			terminer = 1;
	}
	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
/*
	void *mlx = mlx_init();
	void *win = mlx_new_opengl_window(mlx, 100, 100, "ok");
	(void)win;
	mlx_loop(mlx);
	return (0);
*/
}
