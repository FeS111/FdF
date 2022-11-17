/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:21:39 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/17 13:50:40 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 512
#define HEIGHT 512

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}


int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_point	***map;

	if (argc != 2)
		ft_exit("You need exactly one argument (\"path-to-map.fdf\")");
	map = ft_parse_map(argv[1]);
	ft_print_map(map);
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_free_map(map);
	return (0);
}
