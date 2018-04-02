/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/31 16:44:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	ft_keys_down(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->keys.up = 1;
	else if (event.key.keysym.sym == SDLK_DOWN)
		e->keys.down = 1;
	else if (event.key.keysym.sym == SDLK_RIGHT)
		e->keys.right = 1;
	else if (event.key.keysym.sym == SDLK_LEFT)
		e->keys.left = 1;
	else if (event.key.keysym.sym == SDLK_p)
		e->keys.key_p = 1;
	else if (event.key.keysym.sym == SDLK_o)
		e->keys.key_o = 1;
	else if (event.key.keysym.sym == SDLK_KP_8)
		e->keys.key_8 = 1;
	else if (event.key.keysym.sym == SDLK_KP_7)
		e->keys.key_7 = 1;
	else if (event.key.keysym.sym == SDLK_KP_5)
		e->keys.key_5 = 1;
	else if (event.key.keysym.sym == SDLK_KP_4)
		e->keys.key_4 = 1;
	else if (event.key.keysym.sym == SDLK_KP_2)
		e->keys.key_2 = 1;
	else if (event.key.keysym.sym == SDLK_KP_1)
		e->keys.key_1 = 1;
	else if (event.key.keysym.sym == SDLK_w)
		e->keys.key_w = 1;
	else if (event.key.keysym.sym == SDLK_a)
		e->keys.key_a = 1;
	else if (event.key.keysym.sym == SDLK_s)
		e->keys.key_s = 1;
	else if (event.key.keysym.sym == SDLK_d)
		e->keys.key_d = 1;
	else if (event.key.keysym.sym == SDLK_LCTRL)
		e->keys.key_ctrl = 1;
	else if (event.key.keysym.sym == SDLK_SPACE)
		e->keys.key_space = 1;
	else if (event.key.keysym.sym == SDLK_LSHIFT)
		e->speed = 0.2;
}

void	ft_keys_up(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		e->keys.up = 0;
	else if (event.key.keysym.sym == SDLK_DOWN)
		e->keys.down = 0;
	else if (event.key.keysym.sym == SDLK_RIGHT)
		e->keys.right = 0;
	else if (event.key.keysym.sym == SDLK_LEFT)
		e->keys.left = 0;
	else if (event.key.keysym.sym == SDLK_p)
		e->keys.key_p = 0;
	else if (event.key.keysym.sym == SDLK_o)
		e->keys.key_o = 0;
	else if (event.key.keysym.sym == SDLK_KP_8)
		e->keys.key_8 = 0;
	else if (event.key.keysym.sym == SDLK_KP_7)
		e->keys.key_7 = 0;
	else if (event.key.keysym.sym == SDLK_KP_5)
		e->keys.key_5 = 0;
	else if (event.key.keysym.sym == SDLK_KP_4)
		e->keys.key_4 = 0;
	else if (event.key.keysym.sym == SDLK_KP_2)
		e->keys.key_2 = 0;
	else if (event.key.keysym.sym == SDLK_KP_1)
		e->keys.key_1 = 0;
	else if (event.key.keysym.sym == SDLK_w)
		e->keys.key_w = 0;
	else if (event.key.keysym.sym == SDLK_a)
		e->keys.key_a = 0;
	else if (event.key.keysym.sym == SDLK_s)
		e->keys.key_s = 0;
	else if (event.key.keysym.sym == SDLK_d)
		e->keys.key_d = 0;
	else if (event.key.keysym.sym == SDLK_LCTRL)
		e->keys.key_ctrl = 0;
	else if (event.key.keysym.sym == SDLK_SPACE)
		e->keys.key_space = 0;
	else if (event.key.keysym.sym == SDLK_LSHIFT)
		e->speed = 0.1;
}


void	ft_mouse_motion(t_env *e, SDL_Event event)
{
	e->camera.yaw = e->camera.yaw - (event.motion.xrel) * M_PI / 1024.0;
	e->camera.pitch = ft_fclamp(-M_PI / 2, e->camera.pitch - (event.motion.yrel) * M_PI / 1024.0, M_PI / 2);
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
	{
		e->camera.position.x -= sin(e->camera.yaw) * cos(e->camera.pitch) * e->speed;
		e->camera.position.y -= -sin(e->camera.pitch) * e->speed;
		e->camera.position.z -= cos(e->camera.yaw) * cos(e->camera.pitch) * e->speed;
	}
	if (e->keys.key_s)
	{
		e->camera.position.x += sin(e->camera.yaw) * cos(e->camera.pitch) * e->speed;
		e->camera.position.y += -sin(e->camera.pitch) * e->speed;
		e->camera.position.z += cos(e->camera.yaw) * cos(e->camera.pitch) * e->speed;
	}
	if (e->keys.key_a)
	{
		e->camera.position.x -=  cos(e->camera.yaw) * e->speed;
		e->camera.position.z += sin(e->camera.yaw) * e->speed;
	}
	if (e->keys.key_d)
	{
		e->camera.position.x += cos(e->camera.yaw) * e->speed;
		e->camera.position.z -= sin(e->camera.yaw) * e->speed;
	}
	if (e->keys.key_ctrl)
		e->camera.position.y -= e->speed;
	if (e->keys.key_space)
		e->camera.position.y += e->speed;

}
