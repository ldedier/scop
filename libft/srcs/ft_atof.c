/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:43:07 by ldedier           #+#    #+#             */
/*   Updated: 2018/04/24 17:15:55 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_add_float(char const *s, int *i, float *res)
{
	int point;

	point = *i;
	*i += 1;
	while (ft_isdigit(s[*i]))
	{
		*res += (s[*i] - '0') / (float)(ft_pow(10, *i - point));
		*i += 1;
	}
}

float	ft_atof(char const *s)
{
	int		i;
	float	res;
	int		start;

	res = 0;
	start = 0;
	while (ft_isseparator(s[start]))
		start++;
	i = start;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	if (s[i] == '.')
		ft_add_float(s, &i, &res);
	if (s[start] == '-')
		res *= -1;
	return (res);
}
