/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:17:00 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/29 01:58:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	ft_mat4_view(t_vec3 x_axis, t_vec3 y_axis, t_vec3 z_axis, t_vec3 cam_pos)
{
	t_mat4 res;

	res.as_mat[0] = x_axis.x;
	res.as_mat[1] = x_axis.y;
	res.as_mat[2] = x_axis.z;
	res.as_mat[3] = -ft_vec3_dot_product(x_axis, cam_pos);

	res.as_mat[4] = y_axis.x;
	res.as_mat[5] = y_axis.y;
	res.as_mat[6] = y_axis.z;
	res.as_mat[7] = -ft_vec3_dot_product(y_axis, cam_pos);

	res.as_mat[8] = z_axis.x;
	res.as_mat[9] = z_axis.y;
	res.as_mat[10] = z_axis.z;
	res.as_mat[11] = -ft_vec3_dot_product(z_axis, cam_pos);

	res.as_mat[12] = 0;
	res.as_mat[13] = 0;
	res.as_mat[14] = 0;
	res.as_mat[15] = 1;

	return (res);
}

t_mat4	ft_mat4_orientation(t_vec3 x_axis, t_vec3 y_axis, t_vec3 z_axis)
{
	t_mat4 res;

	res.as_mat[0] = x_axis.x;
	res.as_mat[1] = x_axis.y;
	res.as_mat[2] = x_axis.z;
	res.as_mat[3] = 0;

	res.as_mat[4] = y_axis.x;
	res.as_mat[5] = y_axis.y;
	res.as_mat[6] = y_axis.z;
	res.as_mat[7] = 0;

	res.as_mat[8] = z_axis.x;
	res.as_mat[9] = z_axis.y;
	res.as_mat[10] = z_axis.z;
	res.as_mat[11] = 0;

	res.as_mat[12] = 0;
	res.as_mat[13] = 0;
	res.as_mat[14] = 0;
	res.as_mat[15] = 1;

	return (res);
}

t_mat4	ft_mat4_look_at(t_vec3 cam_pos, t_vec3 target_pos, t_vec3 up_axis)
{
	t_vec3	z_axis;
	t_vec3	x_axis;
	t_vec3	y_axis;
//	t_mat4	orientation;

	z_axis = ft_vec3_cmp(target_pos, cam_pos);
	ft_vec3_normalize(&z_axis);


	ft_vec3_normalize(&up_axis);
	x_axis = ft_vec3_cross_product(up_axis, z_axis);

	y_axis = ft_vec3_cross_product(z_axis, x_axis);

return	ft_mat4_view(x_axis, y_axis, z_axis, cam_pos);

	/*
	orientation = ft_mat4_orientation(x_axis, y_axis, z_axis);

	return(ft_mat4_mult(orientation,
				ft_mat4_transpose(ft_mat4_translate(-cam_pos.x, -cam_pos.y, -cam_pos.z))));
*/
}
