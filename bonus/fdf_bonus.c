/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:37:53 by jofoto            #+#    #+#             */
/*   Updated: 2023/06/06 17:51:04 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	rotate_points(t_point *point0, t_point *point1, t_angles angle)
{
	rotate(point0, angle);
	rotate(point1, angle);
}

int	map_x(t_data *d)
{
	static int	curr_pos_x = 0;
	static int	curr_pos_y = 0;

	if (curr_pos_x == d->map->cols - 1)
	{
		if (curr_pos_y == d->map->rows - 1)
		{
			curr_pos_y = 0;
			curr_pos_x = 0;
			return (0);
		}
		curr_pos_x = 0;
		curr_pos_y++;
	}
	d->point0.x = d->x_offset + d->grid_width * curr_pos_x;
	d->point0.y = d->y_offset + d->grid_width * curr_pos_y;
	d->point0.z = d->z_multipliar * (d->map->map[curr_pos_y][curr_pos_x] * \
			d->grid_width / d->initial_gr_wd);
	d->point1.x = d->x_offset + d->grid_width * (curr_pos_x + 1);
	d->point1.y = d->y_offset + d->grid_width * curr_pos_y;
	d->point1.z = d->z_multipliar * (d->map->map[curr_pos_y][curr_pos_x + 1] * \
			d->grid_width / d->initial_gr_wd);
	curr_pos_x++;
	rotate_points(&d->point0, &d->point1, d->angle);
	return (1);
}

int	map_y(t_data *d)
{
	static int	curr_pos_x = 0;
	static int	curr_pos_y = 0;

	if (curr_pos_y == d->map->rows - 1)
	{
		if (curr_pos_x == d->map->cols - 1)
		{
			curr_pos_x = 0;
			curr_pos_y = 0;
			return (0);
		}
		curr_pos_y = 0;
		curr_pos_x++;
	}
	d->point0.y = d->y_offset + d->grid_width * curr_pos_y;
	d->point0.x = d->x_offset + d->grid_width * curr_pos_x;
	d->point0.z = d->z_multipliar * (d->map->map[curr_pos_y][curr_pos_x] * \
			d->grid_width / d->initial_gr_wd);
	d->point1.y = d->y_offset + d->grid_width * (curr_pos_y + 1);
	d->point1.x = d->x_offset + d->grid_width * curr_pos_x;
	d->point1.z = d->z_multipliar * (d->map->map[curr_pos_y + 1][curr_pos_x] * \
			d->grid_width / d->initial_gr_wd);
	curr_pos_y++;
	rotate_points(&d->point0, &d->point1, d->angle);
	return (1);
}

static int	render_next_frame(t_data *d)
{	
	ft_bzero(d->mlx.img.addr, WINDOW_HEIGHT * \
			(d->mlx.img.line_length * 0.99) + \
			WINDOW_WIDTH * d->mlx.img.bits_per_pixel);
	while (map_y(d))
		connect_points(d);
	while (map_x(d))
		connect_points(d);
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.window, d->mlx.img.img, 0, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc == 1)
		return (0);
	init(&d, argv[1]);
	pthread_create(&d.thread, NULL, routine, &d);
	mlx_hook(d.mlx.window, 2, 1L << 0, key_down_hook, &d);
	mlx_hook(d.mlx.window, 17, 1L << 0, destroy, &d);
	mlx_mouse_hook(d.mlx.window, mouse_hook, &d);
	mlx_loop_hook(d.mlx.mlx, render_next_frame, &d);
	mlx_loop(d.mlx.mlx);
	return (0);
}
