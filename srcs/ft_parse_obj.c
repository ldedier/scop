/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:10:27 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/30 02:48:41 by ldedier          ###   ########.fr       */
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

void	ft_print_faces_tmp(t_list *faces)
{
	ft_printf("les faces:\n");

	t_list *ptr;
	ptr = faces;
	t_ivec3 *ivec;
	while (ptr != NULL)
	{
		ivec = (t_ivec3 *)(ptr->content);
		ft_print_ivec3(*ivec);
		ptr = ptr->next;
	}
}

void	ft_print_vertices_tmp(t_list *vertices)
{
	ft_printf("les vertices:\n");

	t_list *ptr;
	ptr = vertices;
	t_vec3 *vec;
	while (ptr != NULL)
	{
		vec = (t_vec3 *)(ptr->content);
		ft_print_vec3(*vec);
		ptr = ptr->next;
	}
}

void		ft_convert_to_array_vertices(t_obj_parser *parser)
{
	int i;
	t_list *ptr;
	t_list *tmp;
	ptr = parser->vertices_tmp;
	parser->vertices = (t_vec3 *)(malloc(sizeof(t_vec3) * parser->nb_vertices + 1));
	i = 1;
	while (i <= parser->nb_vertices)
	{
		parser->vertices[i] = *(t_vec3 *)(ptr->content);
		free(ptr->content);
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		i++;
	}
}

void		ft_convert_to_array_faces(t_obj_parser *parser)
{
	int i;
	t_list *ptr;
	t_list *tmp;
	ptr = parser->faces_tmp;
	parser->faces = (t_ivec3 *)(malloc(sizeof(t_ivec3) * parser->nb_faces));
	i = 0;
	while (i < parser->nb_faces)
	{
		parser->faces[i] = *(t_ivec3 *)(ptr->content);
		free(ptr->content);
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		i++;
	}
}

void	ft_print_vertices(t_obj_parser parser)
{
	int i;

	i = 1;
	printf("vertices:\n");
	while (i <= parser.nb_vertices)
	{
		ft_print_vec3(parser.vertices[i]);
		i++;
	}
}

void	ft_print_draw_array(t_obj_parser parser)
{
	int i;

	i = 0;
	while (i < parser.nb_faces * 9)
	{
		if (i % 3 == 0)
			printf("\n");
		printf("%.6f ", parser.draw_array[i]);
		i++;
	}
}

void	ft_print_faces(t_obj_parser parser)
{
	int i;

	i = 0;
	printf("faces:\n");
	while(i < parser.nb_faces)
	{
		ft_print_ivec3(parser.faces[i]);
		i++;
	}
}

int		ft_fill_draw_array(t_obj_parser *parser)
{
	int nb_faces;
	if (!(parser->draw_array = (float *)(malloc(sizeof(float) * 9 * parser->nb_faces))))
		return (0);
	nb_faces = 0;
//	printf("%d\n", parser->nb_faces);
	while (nb_faces < parser->nb_faces)
	{
		parser->draw_array[9 * nb_faces] = parser->vertices[parser->faces[nb_faces].x].x;
		parser->draw_array[9 * nb_faces + 1] = parser->vertices[parser->faces[nb_faces].x].y;
		parser->draw_array[9 * nb_faces + 2] = parser->vertices[parser->faces[nb_faces].x].z;

		parser->draw_array[9 * nb_faces + 3] = parser->vertices[parser->faces[nb_faces].y].x;
		parser->draw_array[9 * nb_faces + 4] = parser->vertices[parser->faces[nb_faces].y].y;
		parser->draw_array[9 * nb_faces + 5] = parser->vertices[parser->faces[nb_faces].y].z;

		parser->draw_array[9 * nb_faces + 6] = parser->vertices[parser->faces[nb_faces].z].x;
		parser->draw_array[9 * nb_faces + 7] = parser->vertices[parser->faces[nb_faces].z].y;
		parser->draw_array[9 * nb_faces + 8] = parser->vertices[parser->faces[nb_faces].z].z;
		nb_faces++;
	}
	return (1);
}

t_obj_parser		ft_parse_obj(char *filename)
{
	t_obj_parser parser;
	t_mmap map;
	map = ft_map_file(filename);
	parser.i = 0;
	parser.nb_faces = 0;
	parser.nb_vertices = 0;
	parser.vertices_tmp = NULL;
	parser.faces_tmp = NULL;
	parser.materials = NULL;
	ft_process_obj_parsing(&parser, (char *)map.ptr);
	munmap(map.ptr, map.size);
	
//ft_print_faces_tmp(parser.faces_tmp);
//	printf("nb_faces: %d\n", parser.nb_faces);

//	ft_print_vertices_tmp(parser.vertices_tmp);
//	printf("nb_vertices: %d\n", parser.nb_vertices);	
	ft_convert_to_array_vertices(&parser);
	ft_convert_to_array_faces(&parser);
	
//	ft_print_vertices(parser);
//	ft_print_faces(parser);

	ft_fill_draw_array(&parser);
//	ft_print_draw_array(parser);
	return (parser);
}
