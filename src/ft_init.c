/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:41:55 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/22 15:23:35 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*camera_init(t_options *o)
{
	t_camera	*camera;

	camera = (t_camera *) malloc(sizeof(t_camera));
	if (!camera)
		ft_exit("Camare init failed");
	// camera->zoom = fmin(WIDTH / o->points_x / 2, HEIGHT / o->points_y / 2);
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
