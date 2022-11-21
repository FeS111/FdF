/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:52 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/21 18:06:26 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/src/libft.h"
# include <stdarg.h>
# include "../MLX42/MLX42.h"
# include <math.h>

# define WIDTH 1024
# define HEIGHT 1024
# define MULTI 30

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	char		*color;
}	t_point;

typedef struct s_camera
{
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}	t_camera;

typedef struct s_options
{
	int			points_x;
	int			points_y;
	mlx_t		*mlx;
	mlx_image_t	*map;
	t_camera	*camera;
	t_point		**points;
}	t_options;

t_camera	*camera_init(t_options *o);

void		ft_free_two_d_char(char **arr);

t_point		*ft_new_point(int x, int y, int z, char *color);

t_options	*ft_create_options(void);

void		ft_exit(char *error);

void		ft_free_options(t_options *options);

void		ft_print_map(t_point ***map);

void		ft_parse_points(char *path, t_options *options);

t_point		ft_project(t_point p, t_options *o);
#endif