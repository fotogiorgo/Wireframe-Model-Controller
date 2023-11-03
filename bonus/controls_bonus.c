/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:31:18 by jofoto            #+#    #+#             */
/*   Updated: 2023/06/06 17:46:19 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_down_hook(int key, t_data *d)
{
	if (key == 53)
		error(d);
	if (key == 0 || key == 2 || key == 1 || key == 13 || key == 12 || key == 14)
	{
		d->angle.x += 3 * (key == 13);
		d->angle.x -= 3 * (key == 1);
		d->angle.y += 3 * (key == 2);
		d->angle.y -= 3 * (key == 0);
		d->angle.z += 3 * (key == 14);
		d->angle.z -= 3 * (key == 12);
	}
	else if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		d->angle.x_rotation_axis -= 12.0 / WINDOW_HEIGHT * (float)(key == 124);
		d->angle.x_rotation_axis += 12.0 / WINDOW_HEIGHT * (float)(key == 123);
		d->angle.y_rotation_axis -= 24.0 / WINDOW_WIDTH * (float)(key == 125);
		d->angle.y_rotation_axis += 24.0 / WINDOW_WIDTH * (float)(key == 126);
	}
	else if (key == 78 || key == 69)
	{
		d->z_multipliar += (key == 69);
		d->z_multipliar -= (key == 78);
	}
	return (1);
}

int	mouse_hook(int key, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	if (key == 4 || (key == 5 && d->grid_width > 0))
	{
		d->grid_width += (key == 4) * 2;
		d->x_offset -= (key == 4) * d->map->cols;
		d->y_offset -= (key == 4) * d->map->rows;
		d->grid_width -= (key == 5) * 2;
		d->x_offset += (key == 5) * d->map->cols;
		d->y_offset += (key == 5) * d->map->rows;
	}
	return (1);
}
