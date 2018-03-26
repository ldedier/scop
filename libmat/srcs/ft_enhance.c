/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enhance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:45:39 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/27 01:20:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	ft_enhance_mat(t_vec3 vec)
{
	t_mat4 mat;

	mat = (float *)malloc(sizeof(float) * 16);
	mat[0] = vec.x;
	mat[1] = 0;
	mat[2] = 0;
	mat[3] = 0;

	mat[4] = 0;
	mat[5] = vec.y;
	mat[6] = 0;
	mat[7] = 0;

	mat[8] = 0;
	mat[9] = 0;
	mat[10] = vec.z;
	mat[11] = 0;

	mat[12] = 0;
	mat[13] = 0;
	mat[14] = 0;
	mat[15] = 1;
	return(mat);
}
