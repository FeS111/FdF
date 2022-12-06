/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:46:19 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/06 14:19:26 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scroll_hook(double x_delta, double y_delta, void *param)
{
	t_options	*options;

	options = (t_options *) param;
	x_delta = 0;
	if (y_delta > 0)
		options->camera->zoom += 1;
	else if (y_delta < 0 && options->camera->zoom > 1)
		options->camera->zoom -= 1;
	ft_draw(options);
}

static void	ft_check_movement(t_options *o)
{
	if (o->keyboard->w)
		o->camera->y_offset += (o->points_y / 10) + 1 * (o->camera->zoom / 10);
	if (o->keyboard->s)
		o->camera->y_offset -= (o->points_y / 10) + 1 * (o->camera->zoom / 10);
	if (o->keyboard->a)
		o->camera->x_offset += (o->points_x / 10) + 1 * (o->camera->zoom / 10);
	if (o->keyboard->d)
		o->camera->x_offset -= (o->points_x / 10) + 1 * (o->camera->zoom / 10);
	if (o->keyboard->up && o->camera->z_divisor > 1)
		o->camera->z_divisor -= 1;
	if (o->keyboard->down)
		o->camera->z_divisor += 1;
}

static void	ft_check_cursor(void *param)
{
	t_options	*o;
	int			y;
	int			x;

	o = (t_options *) param;
	x = o->mouse->x;
	y = o->mouse->y;
	mlx_get_mouse_pos(o->mlx, &o->mouse->x, &o->mouse->y);
	if (o->mouse->is_pressed)
	{
		if (o->keyboard->control)
			o->camera->gamma += (o->mouse->x - x) * 0.002;
		else
		{
			o->camera->beta += (o->mouse->x - x) * 0.002;
			o->camera->alpha += (o->mouse->y - y) * 0.002;
		}
	}
}

static void	ft_second_loop_hook(t_options *o)
{
	if (mlx_is_key_down(o->mlx, MLX_KEY_S))
		o->keyboard->s = true;
	else
		o->keyboard->s = false;
	if (mlx_is_key_down(o->mlx, MLX_KEY_A))
		o->keyboard->a = true;
	else
		o->keyboard->a = false;
	if (mlx_is_key_down(o->mlx, MLX_KEY_D))
		o->keyboard->d = true;
	else
		o->keyboard->d = false;
	if (mlx_is_key_down(o->mlx, MLX_KEY_UP))
		o->keyboard->up = true;
	else
		o->keyboard->up = false;
	if (mlx_is_key_down(o->mlx, MLX_KEY_DOWN))
		o->keyboard->down = true;
	else
		o->keyboard->down = false;
}

void	ft_loop_hook(void *param)
{
	t_options	*options;

	options = (t_options *) param;
	if (mlx_is_key_down(options->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(options->mlx);
	if (mlx_is_mouse_down(options->mlx, MLX_MOUSE_BUTTON_LEFT))
		options->mouse->is_pressed = true;
	else
		options->mouse->is_pressed = false;
	if (mlx_is_key_down(options->mlx, MLX_KEY_LEFT_CONTROL))
		options->keyboard->control = true;
	else
		options->keyboard->control = false;
	if (mlx_is_key_down(options->mlx, MLX_KEY_W))
		options->keyboard->w = true;
	else
		options->keyboard->w = false;
	ft_second_loop_hook(options);
	ft_check_cursor(param);
	ft_check_movement(options);
	ft_draw(options);
}
