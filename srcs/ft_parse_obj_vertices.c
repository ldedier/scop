/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_obj_vertices.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:47:24 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/24 20:21:08 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		ft_pow(int a, int b)
{
	int i;
	int res;

	res = 1;
	i = 0;
	while (i < b)
	{
		res *= a;
		i++;
	}
	return (res);
}

void	ft_add_float(char const *s, int *i, float *coord)
{
	int point;

	point = *i;
	*i += 1;
	while (ft_isdigit(s[*i]))
	{
		*coord += (s[*i] - '0') / (float)(ft_pow(10, *i - point));
		*i += 1;
	}
}

void	ft_obj_add_coord(int *i, char *s , float *coord)
{
	(void)i;
	(void)s;
	(void)coord;

	int start;
	*coord = 0;
	while (!ft_isdigit(s[*i]) && s[*i] != '-')
		*i += 1;
	start = *i;
	if (s[*i] == '+' || s[*i] == '-')
		*i += 1;
	while (ft_isdigit(s[*i]))
	{
		*coord = *coord * 10 + s[*i] - '0';
		*i += 1;
	}
	if (s[*i] == '.')
		ft_add_float(s, i, coord);
	if (s[start] == '-')
		*coord *= -1;
}

void	ft_obj_vertex(int *i, char *s, t_obj_parser *parser)
{
	t_vec3 *vertex;

	vertex = (t_vec3 *)(malloc(sizeof(t_vec3)));
	ft_obj_add_coord(i, s, &(vertex->x));
	ft_obj_add_coord(i, s, &(vertex->y));
	ft_obj_add_coord(i, s, &(vertex->z));
	while (s[*i] != '\0' && s[*i] != '\n')
		*i += 1;
	ft_lstpushback(&(parser->vertices_tmp), ft_lstnew_ptr(vertex, sizeof(t_vec3)));
}
