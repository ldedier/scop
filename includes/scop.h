/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:54:52 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/27 01:01:19 by ldedier          ###   ########.fr       */
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
	t_vec3		translate;
	t_vec3		rotate;
	t_vec3		enhance;
}				t_env;

t_shader		*shd_new_shader(char *vertex_source, char *fragment_source);
int				shd_charge(t_shader *shader);
int				shd_compile(GLuint	*shader_id, GLenum type, char *filename);
GLuint			shd_getProgramID(t_shader *shader);

#endif
