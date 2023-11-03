/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:20:24 by jofoto            #+#    #+#             */
/*   Updated: 2023/06/06 12:55:12 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

static void	copy_map(t_vector *dst, t_vector *src)
{
	while (src->rows > 0)
	{
		src->rows--;
		dst->map[src->rows] = src->map[src->rows];
	}
}

static t_vector	*realloc_vector(t_vector *map)
{
	t_vector	*new_map;

	new_map = (t_vector *)malloc(sizeof(t_vector));
	if (new_map == 0)
	{
		free_map(map->map, map->rows);
		exit(1);
	}
	new_map->rows_cap = map->rows_cap * 2;
	new_map->rows = map->rows;
	new_map->cols = map->cols;
	new_map->map = (int **)malloc(new_map->rows_cap * sizeof(int *));
	if (new_map->map == 0)
	{
		free (new_map);
		free_map(map->map, map->rows);
		exit(1);
	}
	copy_map(new_map, map);
	free_map(map->map, map->rows);
	free(map);
	return (new_map);
}

static void	add_row(char *line, t_vector *map)
{
	char	**split;
	int		count;

	count = 0;
	split = ft_split(line, ' ');
	if (split == NULL)
	{
		free_map(map->map, map->rows);
		exit(1);
	}
	while (split[map->cols] != NULL && *split[map->cols] != '\n')
		map->cols++;
	map->map[map->rows] = (int *)malloc(sizeof(int) * map->cols);
	if (map->map[map->rows] == NULL)
	{
		free_map(map->map, map->rows);
		exit(1);
	}
	while (split[count] != NULL && *split[count] != '\n')
	{
		map->map[map->rows][count] = ft_atoi(split[count]);
		count++;
	}
	map->cols = count;
	free_split(split);
}

int	get_map(t_data *d, char *fpath)
{
	char	*line;
	int		fd;

	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		exit(0);
	line = get_next_line(fd);
	while (line)
	{
		if (d->map->rows == d->map->rows_cap)
			d->map = realloc_vector(d->map);
		add_row(line, d->map);
		d->map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
