/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:54:52 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/29 00:36:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCOP_H
# define FT_SCOP_H

# include <OpenGL/gl3.h>
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2_mixer/SDL_mixer.h>
# include <fcntl.h>
//# include "mlx.h"
//# include "mlx_opengl.h"
//# include "mlx_int.h"
//# include "mlx_opengl.h"
//# include "mlx_new_window.h"
# include "libft.h"
# include "libmat.h"

typedef struct	s_keys
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			key_o;
	int			key_p;
	int			key_7;
	int			key_8;
	int			key_5;
	int			key_4;
	int			key_2;
	int			key_1;
}				t_keys;

typedef struct	s_shader
{
	GLuint		m_vertex_id;
	GLuint		m_fragment_id;
	GLuint		m_program_id;
	char		*m_vertex_source;
	char		*m_fragment_source;
}				t_shader;

typedef struct	s_env
{
	t_keys		keys;
	t_vec3		translate;
	t_vec3		rotate;
	t_vec3		target;
	t_vec3		up_axis;
	float		scale;
	float		speed;
	t_camera	camera;
}				t_env;

t_shader		*shd_new_shader(char *vertex_source, char *fragment_source);
int				shd_charge(t_shader *shader);
int				shd_compile(GLuint	*shader_id, GLenum type, char *filename);
GLuint			shd_getProgramID(t_shader *shader);

#endif
