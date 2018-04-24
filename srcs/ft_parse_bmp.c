/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:48:32 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/23 17:08:48 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_bmp_parser	ft_parse_bmp(char *filename)
{
	t_mmap map;
	t_bmp_parser parser;
	int size;
	int i = 0;

	map = ft_map_file(filename);
	if ((ft_strlen((char *)map.ptr) < 2) || map.ptr[0] != 'B' || map.ptr[1] != 'M')
	{
		parser.pixels = NULL;
		munmap(map.ptr, map.size);
		return parser;
	}
	parser.width = *(int*)&(map.ptr[18]);
    parser.height = *(int*)&(map.ptr[22]);
	parser.bpp = *(short*)&(map.ptr[28]);
	parser.bitmap_index = *(int*)&(map.ptr[10]);
	
	size =  parser.width * parser.height * (parser.bpp / 8);
	parser.pixels = malloc(sizeof(unsigned char) * size);
	while (i < size)
	{
//		res[i - bit_map_index] = map.ptr[i + 3];
//		res[i + 1 - bit_map_index] = map.ptr[i + 0];
//		res[i + 2 - bit_map_index] = map.ptr[i + 1];
//		res[i + 3 - bit_map_index] = map.ptr[i + 2];

		parser.pixels[size - i - 1] = map.ptr[i + parser.bitmap_index + 0];
		parser.pixels[size - (i + 1) - 1] = map.ptr[i + parser.bitmap_index + 1];
		parser.pixels[size - (i + 2) - 1] = map.ptr[i + parser.bitmap_index + 2];
		parser.pixels[size - (i + 3) - 1] = map.ptr[i + parser.bitmap_index + 3];

//		res[i] = map.ptr[i + bit_map_index + 1];
//		res[(i + 1)] = map.ptr[i + bit_map_index + 3];
//		res[(i + 2)] = map.ptr[i + bit_map_index + 2];
//		res[(i + 3)] = map.ptr[i + bit_map_index + 0];

		i += parser.bpp / 8;
	}
	munmap(map.ptr, map.size);
	if (parser.bpp == 32)
		parser.gl_mode = GL_RGBA;
	else if(parser.bpp == 24)
		parser.gl_mode = GL_RGB;
	return parser;
}
