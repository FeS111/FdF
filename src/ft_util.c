/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:02 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/30 17:13:40 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

void	ft_free_two_d_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_options(t_options *options)
{
	int	i;

	i = 0;
	while (options->points[i] != NULL)
	{
		free(options->points[i]);
		i++;
	}
	free(options->points);
	free(options->camera);
	free(options->mouse);
	free(options->keyboard);
	free(options);
}

t_point	*ft_new_point(int x, int y, int z, t_options *o)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = assign_color(z, o);
	return (point);
}
