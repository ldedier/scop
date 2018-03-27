/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/28 01:25:11 by ldedier          ###   ########.fr       */
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


}

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_env e;

	e.speed = 0.05;
//	e.translate = ft_new_vec3(0,0,0);
//	e.enhance = ft_new_vec3(1,1,1);

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


	e.scale = 1;
	e.rotate.x = 0;
	e.rotate.y = 0;
	e.rotate.z = 0;
	t_mat4 translate_mat = ft_translate_mat(e.translate.x, e.translate.y, e.translate.z);
	t_mat4 scale_mat = ft_scale_mat(e.scale);
	t_mat4 rotate_mat = ft_rotate_mat(e.rotate.x, e.rotate.y, e.rotate.z);
	ft_printf("la matrice de rotation:\n");
	ft_print_mat4(rotate_mat);

	ft_print_mat4(ft_mat4_mult(ft_scale_mat(4), ft_eye_mat()));

	glUseProgram(shader->m_program_id);

	GLint loc_tr = glGetUniformLocation(shader->m_program_id, "Translate_mat");
	if (loc_tr != -1)
		glUniformMatrix4fv(loc_tr, 1, GL_FALSE, translate_mat.as_mat);

	GLint loc_scale = glGetUniformLocation(shader->m_program_id, "Scale_mat");
	if (loc_scale != -1)
		glUniformMatrix4fv(loc_scale, 1, GL_FALSE, scale_mat.as_mat);

	GLint loc_rot = glGetUniformLocation(shader->m_program_id, "Rotate_mat");
	if (loc_rot != -1)
		glUniformMatrix4fv(loc_rot, 1, GL_FALSE, rotate_mat.as_mat);

	while (!terminer)
	{
		while (SDL_PollEvent(&evenements)) {
			if (evenements.type == SDL_KEYDOWN)
				ft_keys_down(&e, evenements);
			if (evenements.type == SDL_KEYUP)
				ft_keys_up(&e, evenements);
			if (evenements.window.event == SDL_WINDOWEVENT_CLOSE || evenements.key.keysym.sym == SDLK_ESCAPE)
				terminer = 1;
		}
		ft_process(&e);
		glClear(GL_COLOR_BUFFER_BIT);
		translate_mat = ft_translate_mat(e.translate.x, e.translate.y, e.translate.z);
		scale_mat = ft_scale_mat(e.scale);	
		rotate_mat = ft_rotate_mat(e.rotate.x, e.rotate.y, e.rotate.z);
		//ft_print_mat4(translate_mat);
		
		glUniformMatrix4fv(loc_tr, 1, GL_FALSE, translate_mat.as_mat);
		glUniformMatrix4fv(loc_scale, 1, GL_FALSE, scale_mat.as_mat);
		glUniformMatrix4fv(loc_rot, 1, GL_FALSE, rotate_mat.as_mat);
   	
		glDrawArrays(GL_TRIANGLES, 0, 3);
		SDL_GL_SwapWindow(fenetre);
	}
	glUseProgram(0);
	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}
