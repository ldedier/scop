/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perspective.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 23:58:47 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/29 00:31:17 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	ft_mat4_perspective(t_camera cam)
{
	t_mat4 res;

	res.as_mat[0] = cam.near / ((tan(cam.fov / 2)) * cam.ratio);
	res.as_mat[1] = 0;
	res.as_mat[2] = 0;
	res.as_mat[3] = 0;

	res.as_mat[4] = 0;
	res.as_mat[5] = cam.near / (tan(cam.fov / 2));
	res.as_mat[6] = 0;
	res.as_mat[7] = 0;

	res.as_mat[8] = 0;
	res.as_mat[9] = 0;
	res.as_mat[10] = -((cam.near + cam.far) / (cam.far - cam.near));
	res.as_mat[11] = -1;

	res.as_mat[12] = 0;
	res.as_mat[13] = 0;
	res.as_mat[14] = -(2 * cam.far * cam.near) / (cam.far - cam.near);
	res.as_mat[15] = 0;

	return (res);
}