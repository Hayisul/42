/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:38:34 by rantonia          #+#    #+#             */
/*   Updated: 2025/05/22 18:42:21 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char *line)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*line)
	{
		if (*line != ' ' && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*line == ' ')
			in_word = 0;
		line++;
	}
	return (count);
}

static void	fill_row(t_point *row, char *line, int y)
{
	char	**split;
	int		x;

	split = ft_split(line, ' ');
	x = 0;
	while (split[x])
	{
		row[x].x = x;
		row[x].y = y;
		row[x].z = ft_atoi(split[x]);
		x++;
	}
	while (x-- > 0)
		free(split[x]);
	free(split);
}

static void	allocate_and_fill(const char *filename, t_map *map)
{
	int		fd;
	t_point	**grid;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	grid = malloc(sizeof(t_point *) * map->height);
	if (!grid)
		return ;
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		grid[y] = malloc(sizeof(t_point) * map->width);
		if (!grid[y])
			return ;
		fill_row(grid[y], line, y);
		free(line);
		y++;
	}
	close(fd);
	map->grid = grid;
}

void	parse_map(const char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: failed to open file\n", 28);
		exit(EXIT_FAILURE);
	}
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (map->height == 0)
			map->width = count_words(line);
		map->height++;
		free(line);
	}
	close(fd);
	allocate_and_fill(filename, map);
}
