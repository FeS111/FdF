/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:07:55 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/30 13:44:21 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

static void	parallel(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

t_point	ft_project(t_point p, t_options *o)
{
	p.x *= o->camera->zoom;
	p.y *= o->camera->zoom;
	p.z *= o->camera->zoom / o->camera->z_divisor;
	p.x -= (o->points_x * o->camera->zoom) / 2;
	p.y -= (o->points_y * o->camera->zoom) / 2;
	ft_rotate_x(&p.y, &p.z, o->camera->alpha);
	ft_rotate_y(&p.x, &p.z, o->camera->beta);
	ft_rotate_z(&p.x, &p.y, o->camera->gamma);
	if (o->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
	else
		parallel(&p.x, &p.y, p.z);
	p.x += (WIDTH) / 2 + o->camera->x_offset;
	p.y += (HEIGHT + o->points_y * o->camera->zoom) / 2 + o->camera->y_offset;
	return (p);
}
