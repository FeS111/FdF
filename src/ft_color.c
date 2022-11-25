/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:13:27 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/25 17:03:36 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_hex_to_int(char *hex)
{
	int	val;
	int	byte;

	while (*hex)
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
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
