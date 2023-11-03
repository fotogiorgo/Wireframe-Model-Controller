/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:13:05 by jofoto            #+#    #+#             */
/*   Updated: 2023/06/06 17:44:02 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(int **map, int rows)
{
	while (rows)
	{
		rows--;
		free(map[rows]);
	}
	free(map);
}

void	error(t_data *d)
{
	mlx_destroy_window(d->mlx.mlx, d->mlx.window);
	free_map(d->map->map, d->map->rows);
	free(d->map);
	exit(1);
}

int	destroy(t_data *d)
{
	error(d);
	exit(0);
}
