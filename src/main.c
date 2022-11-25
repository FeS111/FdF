/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:21:39 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/25 17:03:39 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook(mlx_key_data_t keydata, void *param)
{
	t_options	*options;

	options = (t_options *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(options->mlx);
	ft_draw(options);
}

void	scroll_hook(double x_delta, double y_delta, void *param)
{
	t_options	*options;

	options = (t_options *) param;
	if (y_delta > 0)
		options->camera->zoom += 1;
	else if (y_delta < 0)
		options->camera->zoom -= 1;
	ft_draw(options);
}

void	check_movement(t_options *o)
{
	if (o->keyboard->w)
		o->camera->y_offset -= 3;
	if (o->keyboard->s)
		o->camera->y_offset += 3;
	if (o->keyboard->a)
		o->camera->x_offset -= 3;
	if (o->keyboard->d)
		o->camera->x_offset += 3;
	if (o->keyboard->up && o->camera->z_divisor > 1)
		o->camera->z_divisor -= 1;
	if (o->keyboard->down)
		o->camera->z_divisor += 1;
	ft_draw(o);
}

void	check_cursor(void *param)
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
		ft_draw(o);
	}
}

void	loop_hook(void *param)
{
	t_options	*options;

	options = (t_options *) param;
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
	if (mlx_is_key_down(options->mlx, MLX_KEY_S))
		options->keyboard->s = true;
	else
		options->keyboard->s = false;
	if (mlx_is_key_down(options->mlx, MLX_KEY_A))
		options->keyboard->a = true;
	else
		options->keyboard->a = false;
	if (mlx_is_key_down(options->mlx, MLX_KEY_D))
		options->keyboard->d = true;
	else
		options->keyboard->d = false;
	if (mlx_is_key_down(options->mlx, MLX_KEY_UP))
		options->keyboard->up = true;
	else
		options->keyboard->up = false;
	if (mlx_is_key_down(options->mlx, MLX_KEY_DOWN))
		options->keyboard->down = true;
	else
		options->keyboard->down = false;
	check_cursor(param);
	check_movement(options);
}

int	main(int argc, char **argv)
{
	t_options	*o;
	int			i;

	if (argc != 2)
		ft_exit("You need exactly one argument (\"path-to-map.fdf\")");
	o = ft_create_options();
	ft_parse_points(argv[1], o);
	ft_draw(o);
	mlx_key_hook(o->mlx, &hook, o);
	mlx_scroll_hook(o->mlx, &scroll_hook, o);
	mlx_loop_hook(o->mlx, &loop_hook, o);
	mlx_loop(o->mlx);
	mlx_terminate(o->mlx);
	ft_free_options(o);
	return (0);
}
