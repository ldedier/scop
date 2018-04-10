/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_model_view_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 21:02:11 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/10 01:48:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	ft_mat4_model_view_matrix_vec(t_vec3 translate, t_vec3 scale, t_vec3 rotate)
{
	return ft_mat4_mult(ft_mat4_translate_vec(translate), ft_mat4_mult(ft_mat4_rotate_vec(rotate), ft_mat4_scale_vec(scale)));
}

t_mat4	ft_mat4_model_view_matrix_mat(t_mat4 translate, t_mat4 scale, t_mat4 rotate)
{
	return ft_mat4_mult(translate, ft_mat4_mult(rotate, scale));
}
