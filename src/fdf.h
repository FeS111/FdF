/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:52 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/30 17:00:38 by fschmid          ###   ########.fr       */
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

typedef enum s_projection
{
	ISO,
	PARALLE,
}	t_projection;

typedef struct s_point
{
	int						x;
	int						y;
	int						z;
	u_int32_t				color;
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
	t_projection		projection;
}	t_camera;

typedef struct s_keyboard
{
	bool				control;
	bool				w;
	bool				s;
	bool				a;
	bool				d;
	bool				up;
	bool				down;
}	t_keyboard;

typedef struct s_mouse
{
	bool				is_pressed;
	bool				control_is_pressed;
	int32_t				x;
	int32_t				y;
}	t_mouse;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_options
{
	int			points_x;
	int			points_y;
	int			max;
	int			range;
	int			min;
	mlx_t		*mlx;
	mlx_image_t	*map;
	t_camera	*camera;
	t_mouse		*mouse;	
	t_keyboard	*keyboard;	
	t_point		**points;
}	t_options;


t_rgb		*make_rgb(int r, int g, int b);

void		ft_rotate_x(int *y, int *z, double alpha);

void		ft_rotate_y(int *y, int *z, double alpha);

void		ft_rotate_z(int *y, int *z, double alpha);

void		ft_loop_hook(void *param);

void		ft_scroll_hook(double x_delta, double y_delta, void *param);

void		ft_draw_line(t_options *o, t_point p1, t_point p2);

void		ft_draw(t_options *o);

void		ft_draw_pixel(t_options *o, int x, int y, uint32_t color);

t_camera	*camera_init(t_options *o);

int			assign_color(int z, t_options *o);

t_mouse		*ft_mouse_init(t_options *o);

t_keyboard	*ft_keyboard_init(t_options *o);

void		ft_free_two_d_char(char **arr);

t_point		*ft_new_point(int x, int y, int z, t_options *o);

t_options	*ft_init_options(void);

void		ft_exit(char *error);

void		ft_free_options(t_options *options);

void		ft_print_map(t_point ***map);

void		ft_parse_points(char *path, t_options *options);

t_point		ft_project(t_point p, t_options *o);
#endif