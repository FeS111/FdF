/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:41:55 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/06 15:41:35 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*camera_init(void)
{
	t_camera	*camera;

	camera = (t_camera *) malloc(sizeof(t_camera));
	if (!camera)
		ft_exit("Camare init failed");
	camera->zoom = 18;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 4;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->projection = ISO;
	return (camera);
}

static t_mouse	*ft_mouse_init(void)
{
	t_mouse	*mouse;

	mouse = (t_mouse *) malloc(sizeof(t_mouse));
	if (!mouse)
		ft_exit("Mouse init failed");
	mouse->is_pressed = false;
	mouse->x = 0;
	mouse->y = 0;
	mouse->control_is_pressed = false;
	return (mouse);
}

static t_keyboard	*ft_keyboard_init(void)
{
	t_keyboard	*keboard;

	keboard = (t_keyboard *) malloc(sizeof(t_keyboard));
	if (!keboard)
		ft_exit("Keyboard init failed");
	keboard->control = false;
	keboard->w = false;
	keboard->a = false;
	keboard->d = false;
	keboard->s = false;
	keboard->up = false;
	keboard->down = false;
	return (keboard);
}

t_rgb	*make_rgb(int r, int g, int b)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	rgb->r = r;
	rgb->b = b;
	rgb->g = g;
	return (rgb);
}

t_options	*ft_init_options(void)
{
	t_options	*o;

	o = malloc(sizeof(t_options));
	o->points = NULL;
	o->points_x = 0;
	o->points_y = 0;
	o->mlx = mlx_init(WIDTH, HEIGHT, "FDF", false);
	if (!o->mlx)
		exit(EXIT_FAILURE);
	o->map = mlx_new_image(o->mlx, WIDTH, HEIGHT);
	if (!o->map)
		ft_exit("Failed to draw point");
	if (mlx_image_to_window(o->mlx, o->map, 0, 0) < 0)
		ft_exit("Failed to draw point");
	o->camera = camera_init();
	o->mouse = ft_mouse_init();
	o->keyboard = ft_keyboard_init();
	o->max = 0;
	o->min = 0;
	return (o);
}
