/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/31 03:48:38 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	ft_keys_down(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->keys.up = 1;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->keys.down = 1;
	if (event.key.keysym.sym == SDLK_RIGHT)
		e->keys.right = 1;
	if (event.key.keysym.sym == SDLK_LEFT)
		e->keys.left = 1;
	if (event.key.keysym.sym == SDLK_p)
		e->keys.key_p = 1;
	if (event.key.keysym.sym == SDLK_o)
		e->keys.key_o = 1;
	if (event.key.keysym.sym == SDLK_KP_8)
		e->keys.key_8 = 1;
	if (event.key.keysym.sym == SDLK_KP_7)
		e->keys.key_7 = 1;
	if (event.key.keysym.sym == SDLK_KP_5)
		e->keys.key_5 = 1;
	if (event.key.keysym.sym == SDLK_KP_4)
		e->keys.key_4 = 1;
	if (event.key.keysym.sym == SDLK_KP_2)
		e->keys.key_2 = 1;
	if (event.key.keysym.sym == SDLK_KP_1)
		e->keys.key_1 = 1;
	if (event.key.keysym.sym == SDLK_w)
		e->keys.key_w = 1;
	if (event.key.keysym.sym == SDLK_a)
		e->keys.key_a = 1;
	if (event.key.keysym.sym == SDLK_s)
		e->keys.key_s = 1;
	if (event.key.keysym.sym == SDLK_d)
		e->keys.key_d = 1;
	if (event.key.keysym.sym == SDLK_z)
		e->keys.key_z = 1;
	if (event.key.keysym.sym == SDLK_x)
		e->keys.key_x = 1;


}

void	ft_keys_up(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->keys.up = 0;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->keys.down = 0;
	if (event.key.keysym.sym == SDLK_RIGHT)
		e->keys.right = 0;
	if (event.key.keysym.sym == SDLK_LEFT)
		e->keys.left = 0;
	if (event.key.keysym.sym == SDLK_p)
		e->keys.key_p = 0;
	if (event.key.keysym.sym == SDLK_o)
		e->keys.key_o = 0;
	if (event.key.keysym.sym == SDLK_KP_8)
		e->keys.key_8 = 0;
	if (event.key.keysym.sym == SDLK_KP_7)
		e->keys.key_7 = 0;
	if (event.key.keysym.sym == SDLK_KP_5)
		e->keys.key_5 = 0;
	if (event.key.keysym.sym == SDLK_KP_4)
		e->keys.key_4 = 0;
	if (event.key.keysym.sym == SDLK_KP_2)
		e->keys.key_2 = 0;
	if (event.key.keysym.sym == SDLK_KP_1)
		e->keys.key_1 = 0;
	if (event.key.keysym.sym == SDLK_w)
		e->keys.key_w = 0;
	if (event.key.keysym.sym == SDLK_a)
		e->keys.key_a = 0;
	if (event.key.keysym.sym == SDLK_s)
		e->keys.key_s = 0;
	if (event.key.keysym.sym == SDLK_d)
		e->keys.key_d = 0;
	if (event.key.keysym.sym == SDLK_z)
		e->keys.key_z = 0;
	if (event.key.keysym.sym == SDLK_x)
		e->keys.key_x = 0;


}

void	ft_process(t_env *e)
{
	if (e->keys.up)
		e->translate.y += e->speed;
	if (e->keys.down)
		e->translate.y -= e->speed;
	if (e->keys.right)
		e->translate.x += e->speed;
	if (e->keys.left)
		e->translate.x -= e->speed;
	if (e->keys.key_p)
		e->scale += e->speed;
	if (e->keys.key_o)
		e->scale -= e->speed;
	if (e->keys.key_8)
		e->rotate.x += e->speed;
	if (e->keys.key_7)
		e->rotate.x -= e->speed;
	if (e->keys.key_5)
		e->rotate.y += e->speed;
	if (e->keys.key_4)
		e->rotate.y -= e->speed;
	if (e->keys.key_2)
		e->rotate.z += e->speed;
	if (e->keys.key_1)
		e->rotate.z -= e->speed;
	if (e->keys.key_w)
		e->camera.position.z += e->speed;
	if (e->keys.key_s)
		e->camera.position.z -= e->speed;
	if (e->keys.key_a)
		e->camera.position.x += e->speed;
	if (e->keys.key_d)
		e->camera.position.x -= e->speed;
	if (e->keys.key_z)
		e->camera.position.y += e->speed;
	if (e->keys.key_x)
		e->camera.position.y -= e->speed;

}
