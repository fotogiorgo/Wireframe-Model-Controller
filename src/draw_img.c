/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:31:28 by jofoto            #+#    #+#             */
/*   Updated: 2023/06/06 12:50:00 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(int x, int y, int color, t_data *d)
{
	char	*dst;

	x += WINDOW_WIDTH / d->angle.x_rotation_axis;
	y += WINDOW_HEIGHT / d->angle.y_rotation_axis;
	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT && x >= 0 && y >= 0)
	{
		dst = d->mlx.img.addr + \
			(y * d->mlx.img.line_length + x * (d->mlx.img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	connect_points(t_data *d)
{
	t_conn_pnts_vars	vars;

	get_vars(d->point0, d->point1, &vars);
	if (d->point0.x == d->point1.x)
	{
		while (d->point0.y != d->point1.y)
		{
			my_mlx_pixel_put(d->point0.x, d->point0.y, 0xffffff, d);
			d->point0.y += vars.up;
		}
		return ;
	}
	while (d->point0.x != d->point1.x)
	{
		while (vars.curr_step >= 1)
		{
			my_mlx_pixel_put(d->point0.x, d->point0.y, 0xffffff, d);
			vars.curr_step--;
			d->point0.y += vars.up;
		}
		my_mlx_pixel_put(d->point0.x, d->point0.y, 0xffffff, d);
		vars.curr_step += vars.move_ratio;
		d->point0.x += vars.left;
	}
}
