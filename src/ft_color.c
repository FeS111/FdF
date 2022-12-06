/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:13:27 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/06 14:17:00 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rgb_assign(t_rgb *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

static void	rgb_region_switch(t_rgb *c, int region, int x)
{
	if (region == 0)
		rgb_assign(c, 255, x, 0);
	else if (region == 1)
		rgb_assign(c, 255 - x, 255, 0);
	else if (region == 2)
		rgb_assign(c, 0, 255, x);
	else if (region == 3)
		rgb_assign(c, 0, 255 - x, 255);
	else if (region == 4)
		rgb_assign(c, x, 0, 255);
	else if (region == 5)
		rgb_assign(c, 255, 0, 255 - x);
}

static uint32_t	rgb(double ratio)
{
	int			normalized;
	int			region;
	int			x;
	t_rgb		*c;
	uint32_t	clr;		

	normalized = (int)(ratio * 256 * 6);
	region = normalized / 256;
	x = normalized % 256;
	c = make_rgb(0, 0, 0);
	rgb_region_switch(c, region, x);
	clr = (c->r << 24) | (c->g << 16) | (c->b << 8) | 255;
	free(c);
	return (clr);
}

int	assign_color(int z, t_options *o)
{
	double		ratio;
	uint32_t	color;

	ratio = ((double)z - (double)o->min) / o->range;
	color = rgb(ratio);
	return (color);
}
