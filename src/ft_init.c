/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:41:55 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/22 16:26:01 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*camera_init(t_options *o)
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
	return (camera);
}

t_mouse	*mouse_init(t_options *o)
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

t_keyboard	*keyboard_init(t_options *o)
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
