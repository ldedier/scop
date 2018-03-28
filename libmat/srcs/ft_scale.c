/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 00:07:33 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/28 22:23:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	ft_mat4_scale(float zoom)
{
	t_mat4 mat;

	mat.as_mat[0] = zoom;
	mat.as_mat[1] = 0;
	mat.as_mat[2] = 0;
	mat.as_mat[3] = 0;

	mat.as_mat[4] = 0;
	mat.as_mat[5] = zoom;
	mat.as_mat[6] = 0;
	mat.as_mat[7] = 0;

	mat.as_mat[8] = 0;
	mat.as_mat[9] = 0;
	mat.as_mat[10] = zoom;
	mat.as_mat[11] = 0;

	mat.as_mat[12] = 0;
	mat.as_mat[13] = 0;
	mat.as_mat[14] = 0;
	mat.as_mat[15] = 1;
	return(mat);
}
