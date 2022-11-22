/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:21:39 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/22 15:23:16 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook(mlx_key_data_t keydata, void *param)
{
	t_options	*options;

	options = (t_options *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(options->mlx);
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
		if (o->mouse->control_is_pressed)
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
		options->mouse->control_is_pressed = true;
	else
		options->mouse->control_is_pressed = false;
	check_cursor(param);
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
