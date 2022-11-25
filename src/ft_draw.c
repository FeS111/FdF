/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:53:33 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/25 17:03:40 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_options *o, t_point p1, t_point p2)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p1.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = p1.x;
	pixel_y = p1.y;
	while (pixels)
	{
		ft_draw_pixel(o, pixel_x, pixel_y, p1.color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	ft_draw_pixel(t_options *o, int x, int y, uint32_t color)
{
	if (x < o->map->width && x > 0)
		if (y < o->map->height && y > 0)
			mlx_put_pixel(o->map, x, y, color);
}

void	ft_draw(t_options *o)
{
	int	i;

	i = 0;
	ft_memset(o->map->pixels, 0,
		o->map->width * o->map->height * sizeof(int32_t));
	while (o->points[i] != NULL)
	{
		ft_draw_pixel(o, ft_project(*o->points[i], o).x,
			ft_project(*o->points[i], o).y, o->points[i]->color);
		if (o->points[i + 1] != NULL && (i + 1) % (o->points_x) != 0)
			ft_draw_line(o, ft_project(*o->points[i], o),
				ft_project(*o->points[i + 1], o));
		if (i / o->points_x < o->points_y - 1)
			ft_draw_line(o, ft_project(*o->points[i], o),
				ft_project(*o->points[i + o->points_x], o));
		i++;
	}
}
