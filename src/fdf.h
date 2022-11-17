/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:52 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/17 13:52:47 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/src/libft.h"
# include <stdarg.h>
# include "../MLX42/MLX42.h"

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	char		*color;
}	t_point;

void	ft_free_two_d_char(char **arr);

t_point	*ft_new_point(int x, int y, int z, char *color);

void	ft_exit(char *error);

void	ft_free_map(t_point ***arr);

void	ft_print_map(t_point ***map);

t_point	***ft_parse_map(char *path);

#endif