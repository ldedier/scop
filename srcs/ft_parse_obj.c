/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:10:27 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/24 20:21:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static t_obj_func g_pf_arr[10] =
{
	[enum_obj_hashtag] = ft_obj_hashtag,
	[enum_obj_v] = ft_obj_vertex,
	[enum_obj_f] = ft_obj_face,
	[enum_obj_s] = ft_obj_hashtag,
	[enum_obj_o] = ft_obj_hashtag,
	[enum_obj_g] = ft_obj_hashtag,
	[enum_obj_usemtl] = ft_obj_hashtag,
	[enum_obj_mtllib] = ft_obj_hashtag,
	[enum_obj_vt] = ft_obj_hashtag,
	[enum_obj_vn] = ft_obj_hashtag
};

void	ft_process_obj_parsing(t_obj_parser *parser, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'v' && s[i + 1] == ' ')
			g_pf_arr[enum_obj_v](&i, s, parser);
		else if (s[i] == 'f')
			g_pf_arr[enum_obj_f](&i, s, parser);
		else if (s[i] == 'v' && s[i + 1] == 't')
			g_pf_arr[enum_obj_vt](&i, s, parser);
		else if (s[i] == 'v' && s[i + 1] == 'n')
			g_pf_arr[enum_obj_vt](&i, s, parser);
		else if (s[i] == '#')
			g_pf_arr[enum_obj_hashtag](&i, s, parser);
		else if (s[i] == 'o')
			g_pf_arr[enum_obj_o](&i, s, parser);	
		else if (s[i] == 'g')
			g_pf_arr[enum_obj_g](&i, s, parser);
		else if (s[i] == 's')
			g_pf_arr[enum_obj_s](&i, s, parser);
		else if (!ft_strncmp("mtllib", &(s[i]), 6))
			g_pf_arr[enum_obj_mtllib](&i, s, parser);
		else if (!ft_strncmp("usemtl", &(s[i]), 6))
			g_pf_arr[enum_obj_usemtl](&i, s, parser);
		else
		{
			ft_printf("olaalaaaa: %s\n",&(s[i]));
			exit(1);
		}
		while (s[i] == '\n')
			i++;
	}
}

t_obj_parser		ft_parse_obj(char *filename)
{
	t_obj_parser parser;
	t_mmap map;
	map = ft_map_file(filename);
	parser.i = 0;
	parser.vertices_tmp = NULL;
	parser.faces_tmp = NULL;
	parser.materials = NULL;
	ft_process_obj_parsing(&parser, (char *)map.ptr);
	munmap(map.ptr, map.size);
	return (parser);
}
