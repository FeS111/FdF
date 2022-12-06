/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:21:39 by fschmid           #+#    #+#             */
/*   Updated: 2022/12/06 14:07:39 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_options	*o;

	if (argc != 2)
		ft_exit("You need exactly one argument (\"path-to-map.fdf\")");
	o = ft_init_options();
	ft_parse_points(argv[1], o);
	ft_draw(o);
	mlx_scroll_hook(o->mlx, &ft_scroll_hook, o);
	mlx_loop_hook(o->mlx, &ft_loop_hook, o);
	mlx_loop(o->mlx);
	mlx_terminate(o->mlx);
	ft_free_options(o);
	return (0);
}
