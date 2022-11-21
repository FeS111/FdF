/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:21:39 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/21 18:06:57 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook(void *param)
{
	t_options	*options;

	options = (t_options *) param;
	if (mlx_is_key_down(options->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(options->mlx);
}

int	main(int argc, char **argv)
{
	t_options	*o;
	int			i;

	if (argc != 2)
		ft_exit("You need exactly one argument (\"path-to-map.fdf\")");
	o = ft_create_options();
	ft_parse_points(argv[1], o);
	i = 0;
	while (o->points[i] != NULL)
	{
		mlx_put_pixel(o->map, ft_project(*o->points[i], o).x, ft_project(*o->points[i], o).y, 0xFFFFFFFF);
		i++;
	}
	mlx_loop_hook(o->mlx, &hook, o);
	mlx_loop(o->mlx);
	mlx_terminate(o->mlx);
	ft_free_options(o);
	return (0);
}
