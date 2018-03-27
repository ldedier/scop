/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:52:02 by ldedier           #+#    #+#             */
/*   Updated: 2018/03/27 22:12:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libmat.h"

void	ft_print_mat4(t_mat4 mat)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		k = i;
		j = 0;
		while (j < 4)
		{
			printf("%.1f ", mat.as_mat[k]);
			k += 4;
			j++;
		}
		printf("\n");
		i++;
	}
	printf("FINI\n");
}
