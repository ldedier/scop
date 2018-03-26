/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:42:09 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/27 00:44:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	ft_translate_mat(t_vec3 vec)
{
	t_mat4 mat;

   	mat = (float *)malloc(sizeof(float) * 16);
	mat[0] = 1;
	mat[1] = 0;
	mat[2] = 0;
	mat[3] = 0;

	mat[4] = 0;
	mat[5] = 1;
	mat[6] = 0;
	mat[7] = 0;

	mat[8] = 0;
	mat[9] = 0;
	mat[10] = 1;
	mat[11] = 0;

	mat[12] = vec.x;
	mat[13] = vec.y;
	mat[14] = vec.z;
	mat[15] = 1;
	return(mat);
}
