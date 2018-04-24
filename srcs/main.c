/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:53:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/24 17:32:59 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	int			terminer;
	t_env		e;
	t_shader *shader;
	t_shader *shader_skybox;
	SDL_Event event;

	if (ft_init(&e) == -1)
		return (1);

	glEnable(GL_DEPTH_TEST);      
	glDepthFunc(GL_LEQUAL);  
	glClearDepthf(1.0f);  
	glClear(GL_DEPTH_BUFFER_BIT);   

	terminer = 0;
	shader = shd_new_shader(PATH"/Shaders/basique2D.vert", PATH"/Shaders/basique2D.frag");
	if (!shd_charge(shader))
	{
		ft_printf("shader pas bon\n");
		return (1);
	}

	shader_skybox = shd_new_shader(PATH"/Shaders/skybox.vert", PATH"/Shaders/skybox.frag");
	if (!shd_charge(shader_skybox))
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

float skyboxVertices[] = {
    // positions          
    -1000.0f,  1000.0f, -1000.0f,
    -1000.0f, -1000.0f, -1000.0f,
     1000.0f, -1000.0f, -1000.0f,
     1000.0f, -1000.0f, -1000.0f,
     1000.0f,  1000.0f, -1000.0f,
    -1000.0f,  1000.0f, -1000.0f,

    -1000.0f, -1000.0f,  1000.0f,
    -1000.0f, -1000.0f, -1000.0f,
    -1000.0f,  1000.0f, -1000.0f,
    -1000.0f,  1000.0f, -1000.0f,
    -1000.0f,  1000.0f,  1000.0f,
    -1000.0f, -1000.0f,  1000.0f,

     1000.0f, -1000.0f, -1000.0f,
     1000.0f, -1000.0f,  1000.0f,
     1000.0f,  1000.0f,  1000.0f,
     1000.0f,  1000.0f,  1000.0f,
     1000.0f,  1000.0f, -1000.0f,
     1000.0f, -1000.0f, -1000.0f,

    -1000.0f, -1000.0f,  1000.0f,
    -1000.0f,  1000.0f,  1000.0f,
     1000.0f,  1000.0f,  1000.0f,
     1000.0f,  1000.0f,  1000.0f,
     1000.0f, -1000.0f,  1000.0f,
    -1000.0f, -1000.0f,  1000.0f,

    -1000.0f,  1000.0f, -1000.0f,
     1000.0f,  1000.0f, -1000.0f,
     1000.0f,  1000.0f,  1000.0f,
     1000.0f,  1000.0f,  1000.0f,
    -1000.0f,  1000.0f,  1000.0f,
    -1000.0f,  1000.0f, -1000.0f,

    -1000.0f, -1000.0f, -1000.0f,
    -1000.0f, -1000.0f,  1000.0f,
     1000.0f, -1000.0f, -1000.0f,
     1000.0f, -1000.0f, -1000.0f,
    -1000.0f, -1000.0f,  1000.0f,
     1000.0f, -1000.0f,  1000.0f
};

	GLuint vao_skybox = 1;
	glGenVertexArrays(1, &vao_skybox);
	glBindVertexArray(vao_skybox);

	GLuint skybox_id;
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_CUBE_MAP);
	glGenTextures(1, &skybox_id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, skybox_id);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

//	unsigned char *map;
//	map = ft_parse_bmp(PATH"/resources/skybox_textures/center.bmp");


//	int ok;
//	ok = 0;
//	while(ok < 1024)
//	{
//		ft_printf("%d, %d, %d, %d\n", map[ok], map[ok + 1], map[ok + 2], map[ok + 3]);
///		ok += 4;
//	}
//	printf("%d", map[ok + 10]);

	t_obj_parser parser_o;

	parser_o = ft_parse_obj(PATH"/resources/objs/42.obj");

	t_bmp_parser parser;

	glBindTexture(GL_TEXTURE_2D,0);	
	int i;
	i = 0;
	while (i < 6)
	{
		
		if (i == 0)
			parser = ft_parse_bmp(PATH"/resources/skybox_textures/left.bmp");
		else if (i == 1)
			parser = ft_parse_bmp(PATH"/resources/skybox_textures/right.bmp");
		else if (i == 2)
			parser = ft_parse_bmp(PATH"/resources/skybox_textures/top.bmp");
		else if (i == 3)
			parser = ft_parse_bmp(PATH"/resources/skybox_textures/bottom.bmp");
		else if (i == 4)
			parser = ft_parse_bmp(PATH"/resources/skybox_textures/center.bmp");	
		else
			parser = ft_parse_bmp(PATH"/resources/skybox_textures/farright.bmp");
		
//		parser = ft_parse_bmp(PATH"/resources/textures_rgb/right.bmp");


/*
	int ok;
	ok = 0;
	while(ok < 1024)
	{
		ft_printf("%d, %d, %d, %d\n", parser.pixels[ok], parser.pixels[ok + 1], parser.pixels[ok + 2], parser.pixels[ok + 3]);
		ok += 4;
	}
*/

		/*
		if (i == 0)
			map = ft_parse_bmp(PATH"/resources/skybox_textures/right.bmp");
		else if (i == 1)
			map = ft_parse_bmp(PATH"/resources/skybox_textures/left.bmp");
		else if (i == 2)
			map = ft_parse_bmp(PATH"/resources/skybox_textures/bottom.bmp");
		else if (i == 3)
			map = ft_parse_bmp(PATH"/resources/skybox_textures/top.bmp");
		else if (i == 4)
			map = ft_parse_bmp(PATH"/resources/skybox_textures/center.bmp");	
		else
			map = ft_parse_bmp(PATH"/resources/skybox_textures/farright.bmp");
		*/
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, parser.gl_mode, 1024, 1024, 0, parser.gl_mode, GL_UNSIGNED_BYTE, parser.pixels);
		i++;
	}
	GLuint vbo_skybox[1];
	glGenBuffers(2, vbo_skybox);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_skybox[0]);
	glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), skyboxVertices, GL_STATIC_DRAW);
	location = glGetAttribLocation(shader_skybox->m_program_id, "in_Vertex_skybox");
	glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	e.scale = 1;
	e.rotate.x = 0;
	e.rotate.y = 0;
	e.rotate.z = 0;
	
	t_mat4 translate_mat = ft_mat4_translate(e.translate.x, e.translate.y, e.translate.z);
	t_mat4 scale_mat = ft_mat4_scale(e.scale);
	t_mat4 rotate_mat = ft_mat4_rotate(e.rotate.x, e.rotate.y, e.rotate.z);

	e.camera.position.x = 0;
	e.camera.position.y = 0;
	e.camera.position.z = 5;
	
	e.up_axis.x = 0;
	e.up_axis.y = 1;
	e.up_axis.z = 0;
	
	e.camera.yaw = 0;
	e.camera.pitch = 0;
	t_mat4 view_mat = ft_mat4_look_fps(e.camera.position,e.camera.yaw, e.camera.pitch);
//	t_mat4 view_mat = ft_mat4_eye();

	t_mat4 model_view_mat = ft_mat4_model_view_matrix_mat(translate_mat, scale_mat, rotate_mat);
	ft_printf("la matrice de view:\n");
	ft_print_mat4(view_mat);

	e.speed = 0.1;
	e.camera.fov = (70.f/ 180.f) * M_PI;
	e.camera.ratio = 1200.0 / 800.0;
	e.camera.near = 0.1;
	e.camera.far = 10000;

	t_mat4 proj_mat = ft_mat4_perspective(e.camera);
	// ft_printf("la matrice de perspective:\n");
	ft_print_mat4(proj_mat);
		
	glUseProgram(shader->m_program_id);	
	glBindVertexArray(vao);

	GLint loc_mv = glGetUniformLocation(shader->m_program_id, "Model_mat");
	if (loc_mv != -1)
		glUniformMatrix4fv(loc_mv,  1, GL_FALSE, model_view_mat.as_mat);

	GLint loc_view = glGetUniformLocation(shader->m_program_id, "View_mat");
	if (loc_view != -1)
		glUniformMatrix4fv(loc_view, 1, GL_FALSE, view_mat.as_mat);

	GLint loc_proj = glGetUniformLocation(shader->m_program_id, "Projection_mat");
	if (loc_proj != -1)
		glUniformMatrix4fv(loc_proj, 1, GL_FALSE, proj_mat.as_mat);
	
	glUseProgram(shader_skybox->m_program_id);
	glBindVertexArray(vao_skybox);
	
	GLint loc_tr_s = glGetUniformLocation(shader_skybox->m_program_id, "Translate_mat");
	if (loc_tr_s != -1)
		glUniformMatrix4fv(loc_tr_s, 1, GL_FALSE, translate_mat.as_mat);

	GLint loc_view_s = glGetUniformLocation(shader_skybox->m_program_id, "View_mat");
	if (loc_view_s != -1)
		glUniformMatrix4fv(loc_view_s, 1, GL_FALSE, view_mat.as_mat);

	GLint loc_proj_s = glGetUniformLocation(shader_skybox->m_program_id, "Projection_mat");
	if (loc_proj_s != -1)
		glUniformMatrix4fv(loc_proj_s, 1, GL_FALSE, proj_mat.as_mat);

	//	glEnable(GL_DEPTH_TEST);
	//  glClearColor(0.5,0,0.5,0.0);

	while (!terminer)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
				ft_keys_down(&e, event);
			if (event.type == SDL_KEYUP)
				ft_keys_up(&e, event);
			if (event.type == SDL_MOUSEMOTION)
				ft_mouse_motion(&e, event);
			if (event.window.event == SDL_WINDOWEVENT_CLOSE || (event.key.keysym.sym == SDLK_ESCAPE && event.type == SDL_KEYDOWN))
				terminer = 1;
		}
		ft_process(&e);
		glClearDepthf(1.0f);  
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		translate_mat = ft_mat4_translate(e.translate.x, e.translate.y, e.translate.z);
		scale_mat = ft_mat4_scale(e.scale);
		rotate_mat = ft_mat4_rotate(e.rotate.x, e.rotate.y, e.rotate.z);
		view_mat = ft_mat4_look_fps(e.camera.position,e.camera.yaw, e.camera.pitch);
		model_view_mat = ft_mat4_model_view_matrix_mat(translate_mat, scale_mat, rotate_mat);
		
		//ft_print_mat4(translate_mat);
		
		glUseProgram(shader->m_program_id);
		glBindVertexArray(vao);

		glUniformMatrix4fv(loc_mv, 1, GL_FALSE, model_view_mat.as_mat);
		glUniformMatrix4fv(loc_view, 1, GL_FALSE, view_mat.as_mat);
		glUniformMatrix4fv(loc_proj, 1, GL_FALSE, proj_mat.as_mat);
		glDrawArrays(GL_TRIANGLES, 0, 108);

		glUseProgram(shader_skybox->m_program_id);
		glBindVertexArray(vao_skybox);
		
		glUniformMatrix4fv(loc_tr_s, 1, GL_FALSE, ft_mat4_translate(e.camera.position.x,e.camera.position.y,e.camera.position.z).as_mat);
		glUniformMatrix4fv(loc_view_s, 1, GL_FALSE, view_mat.as_mat);
		glUniformMatrix4fv(loc_proj_s, 1, GL_FALSE, proj_mat.as_mat);

		glDrawArrays(GL_TRIANGLES, 0, 108);
		SDL_GL_SwapWindow(e.sdl.window);
	}
	ft_quit(&e);
	return 0;
}
