/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:18:02 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/22 11:35:30 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static int	ft_count(char **arr, int f)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i] != 0)
	{
		if (!ft_strchr(arr[i], ' '))
			count++;
		else
			count += ft_count(ft_split(arr[i], ' '), 1);
		i++;
	}
	if (f == 1)
		free(arr);
	return (count);
}

static char	*ft_read_map(char *path)
{
	char	*map;
	char	*line;
	int		fd;

	map = ft_strdup("");
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}

static t_point	*ft_convert_to_point(char *col, int x, int y)
{
	t_point	*result;
	char	**tmp;

	result = malloc(sizeof(t_point));
	if (!result)
		ft_exit("Allocation failed");
	tmp = ft_split(col, ',');
	if (tmp[1] == 0)
		tmp[1] = NULL;
	result = ft_new_point(x, y, ft_atoi(tmp[0]), tmp[1]);
	free(tmp[0]);
	free(tmp);
	return (result);
}

static t_point	**ft_allocate_points(char **lines)
{
	t_point	**points;

	points = malloc(sizeof(t_point *) * (ft_count(lines, 0) + 1));
	if (!points)
		ft_exit("Allocation failed");
	return (points);
}

void	ft_parse_points(char *path, t_options *options)
{
	char	**lines;
	char	**cols;
	int		i;
	int		k;
	int		j;

	lines = ft_split(ft_read_map(path), '\n');
	options->points = ft_allocate_points(lines);
	i = 0;
	k = 0;
	while (lines[i] != 0)
	{
		j = 0;
		cols = ft_split(lines[i], ' ');
		while (cols[j] != 0)
		{
			options->points[k++] = ft_convert_to_point(cols[j], j, i);
			j++;
		}
		options->points_x = j;
		i++;
	}
	options->points_y = i;
	options->points[k] = NULL;
	ft_free_two_d_char(lines);
	ft_free_two_d_char(cols);
}
