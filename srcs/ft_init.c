/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/30 16:56:18 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		ft_init(t_env *e)
{
	e->speed = 0.05;
	e->sdl.window = NULL;
	e->sdl.context = NULL;

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

	e->sdl.window = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (e->sdl.window == NULL)
	{
		SDL_Quit();
		return (-1);
	}
	e->sdl.context = SDL_GL_CreateContext(e->sdl.window);
	if (e->sdl.context == NULL)
	{
		SDL_DestroyWindow(e->sdl.window);
		return -1;
	}
	return(0);
}
