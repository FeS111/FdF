/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:02 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/22 16:15:41 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

void	ft_free_two_d_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_options(t_options *options)
{
	int	i;

	i = 0;
	while (options->points[i] != NULL)
	{
		if (options->points[i]->color != NULL)
			free(options->points[i]->color);
		free(options->points[i]);
		i++;
	}
	free(options->points);
	free(options->camera);
	free(options->mouse);
	free(options->keyboard);
	free(options);
}

t_options	*ft_create_options(void)
{
	t_options	*o;

	o = malloc(sizeof(t_options));
	o->points = NULL;
	o->points_x = 0;
	o->points_y = 0;
	o->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!o->mlx)
		exit(EXIT_FAILURE);
	o->map = mlx_new_image(o->mlx, WIDTH, HEIGHT);
	if (!o->map)
		ft_exit("Failed to draw point");
	if (mlx_image_to_window(o->mlx, o->map, 0, 0) < 0)
		ft_exit("Failed to draw point");
	o->camera = camera_init(o);
	o->mouse = mouse_init(o);
	o->keyboard = keyboard_init(o);
	return (o);
}

t_point	*ft_new_point(int x, int y, int z, char *color)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	return (point);
}
