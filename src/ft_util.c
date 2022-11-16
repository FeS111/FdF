/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:02 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/16 17:00:25 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_two_d_char(char **arr)
{
	int	i;

	i = -1;
	while (arr[i++] != 0)
		free(arr[i]);
	free(arr);
}

void	ft_free_two_d_int(int **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i] - 1);
		i++;
	}
	free(arr);
}
