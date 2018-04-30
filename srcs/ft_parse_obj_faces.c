/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_obj_faces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:45:42 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/30 02:55:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	ft_obj_hashtag(int *i, char *s, t_obj_parser *parser)
{
	(void)parser;
	while (s[*i] != '\0' && s[*i] != '\n')
		*i += 1;
}

void	ft_obj_add_index(int *i, char *s , int *index)
{
	*index = 0;
	while (!ft_isdigit(s[*i]) && s[*i] != '\n' && s[*i] != '\0')
		*i += 1;
	while (ft_isdigit(s[*i]))
	{
		*index = *index * 10 + s[*i] - '0';
		*i += 1;
	}
}

int	ft_obj_add_index_fourth(int *i, char *s , int *index)
{
	*index = 0;
	while (!ft_isdigit(s[*i]) && s[*i] != '\n' && s[*i] != '\0')
		*i += 1;
	if (!ft_isdigit(s[*i]))
		return (0);
	while (ft_isdigit(s[*i]))
	{
		*index = *index * 10 + s[*i] - '0';
		*i += 1;
	}
	return (1);
}

void	ft_obj_face(int *i, char *s, t_obj_parser *parser)
{
	t_ivec3 *face;
	t_ivec3 tmp;
	
	ft_obj_add_index(i, s, &(tmp.x));
	ft_obj_add_index(i, s, &(tmp.y));
	ft_obj_add_index(i, s, &(tmp.z));

	face = (t_ivec3 *)(malloc(sizeof(t_ivec3)));
	*face = tmp;
	ft_lstpushback(&(parser->faces_tmp), ft_lstnew(face, sizeof(t_ivec3)));
	parser->nb_faces++;
	free(face);
	face = (t_ivec3 *)(malloc(sizeof(t_ivec3)));
	tmp.y = tmp.z;
	if (ft_obj_add_index_fourth(i, s, &(tmp.z)))
	{
		*face = tmp;
		ft_lstpushback(&(parser->faces_tmp), ft_lstnew_ptr(face, sizeof(t_ivec3)));
		parser->nb_faces++;
	}
	while (s[*i] != '\0' && s[*i] != '\n')
		*i += 1;
}
