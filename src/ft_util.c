/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:02 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/17 13:52:26 by fschmid          ###   ########.fr       */
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

	i = -1;
	while (arr[i++] != 0)
		free(arr[i]);
	free(arr);
}

void	ft_free_map(t_point ***arr)
{
	int	i;
	int	k;

	i = 0;
	while (arr[i] != NULL)
	{
		k = 0;
		while (arr[i][k] != NULL)
		{
			free(arr[i][k]->color);
			free(arr[i][k]);
			k++;
		}
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_point	*ft_new_point(int x, int y, int z, char *color)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	return (point);
}
