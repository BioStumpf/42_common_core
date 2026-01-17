/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:49:08 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/14 16:17:15 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *point, double angle)
{
	double	y;

	if (angle == 0)
		return ;
	y = point->y;
	point->y = y * cos(angle) - point->z * sin(angle);
	point->z = y * sin(angle) + point->z * cos(angle);
}

void	rotate_y(t_point *point, double angle)
{
	double	x;

	if (angle == 0)
		return ;
	x = point->x;
	point->x = x * cos(angle) + point->z * sin(angle);
	point->z = -x * sin(angle) + point->z * cos(angle);
}

void	rotate_z(t_point *point, double angle)
{
	double	x;

	if (angle == 0)
		return ;
	x = point->x;
	point->x = x * cos(angle) - point->y * sin(angle);
	point->y = x * sin(angle) + point->y * cos(angle);
}

void	transform_iso(t_point *point)
{
	double	x;
	double	y;

	x = point->x;
	y = point->y;
	point->x = sqrt(2) / 2 * (x - y);
	point->y = 1 / sqrt(3) * (x + y - point->z);
	point->z = sqrt((2 / 3)) * (0.5 * x - 0.5 * y + point->z);
	//rotate_z(point, M_PI / 4);
	//rotate_x(point, atan(1 / sqrt(2)));
}

