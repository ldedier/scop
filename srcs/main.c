/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/31 04:03:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	int			terminer;
	t_env		e;
	t_shader *shader;
	SDL_Event event;

	if (ft_init(&e) == -1)
		return (1);

	glEnable(GL_DEPTH_TEST);      
	glDepthFunc(GL_LEQUAL);  
	glClearDepthf(1.0f);  
	glClear(GL_DEPTH_BUFFER_BIT);   

	terminer = 0;
	shader = shd_new_shader("Shaders/basique2D.vert", "Shaders/basique2D.frag");
	if (!shd_charge(shader))
	{
		ft_printf("shader pas bon\n");
		return (1);
	}

	float vertices[] = {
		-1.0, -1.0, -1.0,   1.0, -1.0, -1.0,   1.0, 1.0, -1.0,     // Face 1
		-1.0, -1.0, -1.0,   -1.0, 1.0, -1.0,   1.0, 1.0, -1.0,     // Face 1

		1.0, -1.0, 1.0,   1.0, -1.0, -1.0,   1.0, 1.0, -1.0,       // Face 2
		1.0, -1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, -1.0,         // Face 2

		-1.0, -1.0, 1.0,   1.0, -1.0, 1.0,   1.0, -1.0, -1.0,      // Face 3
		-1.0, -1.0, 1.0,   -1.0, -1.0, -1.0,   1.0, -1.0, -1.0,    // Face 3

		-1.0, -1.0, 1.0,   1.0, -1.0, 1.0,   1.0, 1.0, 1.0,        // Face 4
		-1.0, -1.0, 1.0,   -1.0, 1.0, 1.0,   1.0, 1.0, 1.0,        // Face 4

		-1.0, -1.0, -1.0,   -1.0, -1.0, 1.0,   -1.0, 1.0, 1.0,     // Face 5
		-1.0, -1.0, -1.0,   -1.0, 1.0, -1.0,   -1.0, 1.0, 1.0,     // Face 5

		-1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, -1.0,         // Face 6
		-1.0, 1.0, 1.0,   -1.0, 1.0, -1.0,   1.0, 1.0, -1.0};      // Face 6

	//	float vertices[] = {-0.5, -0.5, 0.0,  0.0, 0.5,0.0, 0.5,-0.5,0.0 };

	float colors[] = {
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 1 ROUGE
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 1

		0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 2 VERT
		0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 2

		0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,           // Face 3 BLEU
		0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,           // Face 3

		1.0, 1.0, 0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,           // Face 4 YELLOW
		1.0, 1.0, 0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0,           // Face 4

		0.0, 1.0, 1.0,   0.0, 1.0, 1.0,   0.0, 1.0, 1.0,           // Face 5 CYAN
		0.0, 1.0, 1.0,   0.0, 1.0, 1.0,   0.0, 1.0, 1.0,           // Face 5

		1.0, 0.0, 1.0,   1.0, 0.0, 1.0,   1.0, 0.0, 1.0,           // Face 6
		1.0, 0.0, 1.0,   1.0, 0.0, 1.0,   1.0, 0.0, 1.0};          // Face 6

/*
	float colors[] = {
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0
	};
*/
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	GLuint vbo[2];
	GLint location;
	glGenBuffers(2, vbo);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), vertices, GL_STATIC_DRAW);
	location = glGetAttribLocation(shader->m_program_id, "in_Vertex");
	glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, NULL);	

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), colors, GL_STATIC_DRAW);
	location = glGetAttribLocation(shader->m_program_id, "in_Colors");
	glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	e.scale = 0.11;
	e.rotate.x = 0;
	e.rotate.y = 0;
	e.rotate.z = 0;
	
	t_mat4 translate_mat = ft_mat4_translate(e.translate.x, e.translate.y, e.translate.z);
	t_mat4 scale_mat = ft_mat4_scale(e.scale);
	t_mat4 rotate_mat = ft_mat4_rotate(e.rotate.x, e.rotate.y, e.rotate.z);

	e.camera.position.x = 2;
	e.camera.position.y = 0;
	e.camera.position.z = 0;

	e.target.x = 0;
	e.target.y = 0;
	e.target.z = 0;
	
	e.up_axis.x = 0;
	e.up_axis.y = 1;
	e.up_axis.z = 0;
	
	t_mat4 view_mat = ft_mat4_look_at(e.camera.position, e.target, e.up_axis);
//	t_mat4 view_mat = ft_mat4_eye();

	ft_printf("la matrice de view:\n");
	ft_print_mat4(view_mat);

	e.camera.fov = 1.22173;
	e.camera.ratio = 1200.0 / 800.0 ;
	e.camera.near = 0.01;
	e.camera.far = 500;

	t_mat4 proj_mat = ft_mat4_perspective(e.camera);
	//t_mat4 proj_mat = ft_mat4_eye();
	// ft_printf("la matrice de perspective:\n");
	ft_print_mat4(proj_mat);
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

	GLint loc_view = glGetUniformLocation(shader->m_program_id, "View_mat");
	if (loc_view != -1)
		glUniformMatrix4fv(loc_view, 1, GL_FALSE, view_mat.as_mat);

	GLint loc_proj = glGetUniformLocation(shader->m_program_id, "Projection_mat");
	if (loc_proj != -1)
		glUniformMatrix4fv(loc_proj, 1, GL_FALSE, proj_mat.as_mat);
	
	while (!terminer)
	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN)
				ft_keys_down(&e, event);
			if (event.type == SDL_KEYUP)
				ft_keys_up(&e, event);
			if (event.window.event == SDL_WINDOWEVENT_CLOSE || event.key.keysym.sym == SDLK_ESCAPE)
				terminer = 1;
		}
		ft_process(&e);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		translate_mat = ft_mat4_translate(e.translate.x, e.translate.y, e.translate.z);
		scale_mat = ft_mat4_scale(e.scale);
		rotate_mat = ft_mat4_rotate(e.rotate.x, e.rotate.y, e.rotate.z);
		
		view_mat = ft_mat4_look_at(e.camera.position, e.target, e.up_axis);
		ft_printf("la matrice de view:\n");
		ft_print_mat4(view_mat);
	
		ft_printf("la position de la camera\n");

		ft_print_vec3(e.camera.position);
		glUniformMatrix4fv(loc_tr, 1, GL_FALSE, translate_mat.as_mat);
		glUniformMatrix4fv(loc_scale, 1, GL_FALSE, scale_mat.as_mat);
		glUniformMatrix4fv(loc_rot, 1, GL_FALSE, rotate_mat.as_mat);
		glUniformMatrix4fv(loc_view, 1, GL_FALSE, view_mat.as_mat);
		glUniformMatrix4fv(loc_proj, 1, GL_FALSE, proj_mat.as_mat);
		glDrawArrays(GL_TRIANGLES, 0, 108);
		SDL_GL_SwapWindow(e.sdl.window);
	}
	ft_quit(&e);
	return 0;
}
