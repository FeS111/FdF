/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:21:39 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/17 16:30:49 by fschmid          ###   ########.fr       */
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
	t_point	**points;

	if (argc != 2)
		ft_exit("You need exactly one argument (\"path-to-map.fdf\")");
	points = NULL;
	points = ft_parse_points(argv[1], points);
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_free_points(points);
	return (0);
}
