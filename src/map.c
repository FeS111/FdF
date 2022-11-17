/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:18:02 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/17 13:54:29 by fschmid          ###   ########.fr       */
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

static t_point	**ft_convert_line(char *line, int y)
{
	int		i;
	t_point	**result;
	char	**cols;
	char	**tmp;

	i = 0;
	cols = ft_split(line, ' ');
	result = malloc(sizeof(t_point *) * (ft_line_count(cols)) + 1);
	if (!result)
		ft_exit("Allocation failed");
	while (cols[i] != 0)
	{
		tmp = ft_split(cols[i], ',');
		if (tmp[1] == 0)
			tmp[1] = NULL;
		result[i] = ft_new_point(i, y, ft_atoi(tmp[0]), tmp[1]);
		++i;
	}
	result[i] = NULL;
	ft_free_two_d_char(cols);
	ft_free_two_d_char(tmp);
	return (result);
}

void	ft_print_map(t_point ***map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i] != NULL)
	{
		k = 0;
		while (map[i][k] != NULL)
		{
			ft_printf("%d,%s\t", map[i][k]->z, map[i][k]->color);
			k++;
		}
		ft_printf("\n");
		i++;
	}
}

t_point	***ft_parse_map(char *path)
{
	char	**map_lines;
	t_point	***map;
	int		i;

	map_lines = ft_split(ft_read_map(path), '\n');
	map = malloc(sizeof(t_point *) * (ft_line_count(map_lines) + 1));
	if (!map)
		ft_exit("Allocation failed");
	i = 0;
	while (map_lines[i] != 0)
	{
		map[i] = ft_convert_line(map_lines[i], i);
		i++;
	}
	map[i] = NULL;
	ft_free_two_d_char(map_lines);
	return (map);
}
