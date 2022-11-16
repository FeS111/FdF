/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:18:02 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/16 16:54:48 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static int	ft_line_count(char **map_lines)
{
	int	i;

	i = 0;
	while (map_lines[i] != 0)
		i++;
	return (i);
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

static int	*ft_convert_line(char *line)
{
	int		i;
	int		*result;
	char	**cols;

	i = 0;
	cols = ft_split(line, ' ');
	result = malloc(sizeof(int) * (ft_line_count(cols)) + 1);
	result[0] = ft_line_count(cols);
	result++;
	while (cols[i] != 0)
	{
		result[i] = ft_atoi(cols[i]);
		++i;
	}
	ft_free_two_d_char(cols);
	return (result);
}

void	ft_print_map(int **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i] != NULL)
	{
		k = 0;
		while (k < *(map[i] - 1))
		{
			ft_printf("%d\t", map[i][k]);
			k++;
		}
		ft_printf("\n");
		i++;
	}
}

int	**ft_parse_map(char *path)
{
	char	**map_lines;
	int		**map;
	int		i;

	map_lines = ft_split(ft_read_map(path), '\n');
	map = malloc(sizeof(int *) * (ft_line_count(map_lines) + 1));
	i = 0;
	while (map_lines[i] != 0)
	{
		map[i] = ft_convert_line(map_lines[i]);
		i++;
	}
	map[i] = NULL;
	ft_free_two_d_char(map_lines);
	return (map);
}
