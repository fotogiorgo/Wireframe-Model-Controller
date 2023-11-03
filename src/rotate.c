/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofoto <jofoto@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:23:29 by jofoto            #+#    #+#             */
/*   Updated: 2023/06/06 12:10:18 by jofoto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_x(t_point *coords, float angle)
{
	int	y;
	int	z;

	z = coords->z;
	y = coords->y;
	coords->y = cos(angle) * y - sin(angle) * z;
	coords->z = sin(angle) * y + cos(angle) * z;
}

void	rotate_y(t_point *coords, float angle)
{
	int	x;
	int	z;

	z = coords->z;
	x = coords->x;
	coords->x = cos(angle) * x + sin(angle) * z;
	coords->z = -sin(angle) * x + cos(angle) * z;
}

void	rotate_z(t_point *coords, float angle)
{
	int	x;
	int	y;

	y = coords->y;
	x = coords->x;
	coords->x = cos(angle) * x - sin(angle) * y;
	coords->y = sin(angle) * x + cos(angle) * y;
}

void	rotate(t_point *coords, t_angles angle)
{
	rotate_x(coords, angle.x * RADIANT_CONV);
	rotate_y(coords, angle.y * RADIANT_CONV);
	rotate_z(coords, angle.z * RADIANT_CONV);
}
