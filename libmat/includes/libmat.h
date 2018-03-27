/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:16:34 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/28 01:29:49 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBMAT_H
# define FT_LIBMAT_H

#include <stdlib.h>
#include <math.h>

typedef struct		s_vec2
{
	float			x;
	float			y;
}					t_vec2;

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef struct		s_vec4_repr
{
	t_vec4			vec1;
	t_vec4			vec2;
	t_vec4			vec3;
	t_vec4			vec4;
}					t_vec4_repr;

typedef union		u_mat4
{
	t_vec4_repr		as_vec4;
	float			as_mat[16];
}					t_mat4;

t_mat4				ft_mat4_mult(t_mat4 mat1, t_mat4 mat2);
t_mat4				ft_eye_mat(void);
t_mat4				ft_scale_mat(float zoom);
t_mat4				ft_translate_mat(float x, float y, float z);
t_mat4				ft_rotate_mat_x(float alpha);
t_mat4				ft_rotate_mat_y(float beta);
t_mat4				ft_rotate_mat_z(float gamma);
t_mat4				ft_rotate_mat(float alpha, float beta, float gamma);
t_vec3				ft_new_vec3(float x, float y, float z);
void				ft_print_mat4(t_mat4 mat);
#endif
