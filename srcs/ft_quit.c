/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:52:25 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/30 16:52:28 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	ft_quit(t_env *e)
{
	glUseProgram(0);
	SDL_GL_DeleteContext(e->sdl.context);
	SDL_DestroyWindow(e->sdl.window);
	SDL_Quit();
}
