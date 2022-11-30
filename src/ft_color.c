/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:13:27 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/30 16:12:40 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_hex_to_int(char *hex)
{
	int	val;
	int	i;

	val = 0;
	i = 0;
	while (base(hex[i], 16) != -1)
	{
		val = val * 16;
		val += base(hex[i], 16);
		i++;
	}
	return (val);
}

static int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_parse_color(char *str)
{
	int	r;
	int	g;
	int	b;

	if (str == NULL)
		return (0xFFFFFFFF);
	r = ft_hex_to_int(ft_substr(str, 2, 2));
	g = ft_hex_to_int(ft_substr(str, 4, 2));
	b = ft_hex_to_int(ft_substr(str, 6, 2));
	return (ft_get_rgba(r, g, b, 255));
}
