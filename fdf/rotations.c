/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:49:08 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/23 15:14:58 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *point, double angle, double center_y)
{
	double	y;

	if (angle == 0)
		return ;
	y = point->y - center_y;
	point->y = y * cos(angle) - point->z * sin(angle);
	point->z = y * sin(angle) + point->z * cos(angle);
	point->y += center_y;
}

void	rotate_y(t_point *point, double angle, double center_x)
{
	double	x;

	if (angle == 0)
		return ;
	x = point->x - center_x;
	point->x = x * cos(angle) + point->z * sin(angle);
	point->z = -x * sin(angle) + point->z * cos(angle);
	point->x += center_x;	
}

void	rotate_z(t_point *point, double angle, double center_x, double center_y)
{
	double	x;
	double	y;

	if (angle == 0)
		return ;
	x = point->x - center_x;
	y = point->y - center_y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
	point->x += center_x;	
	point->y += center_y;	
}

void	transform_iso(t_point *point)
{
	double	x;

	x = point->x;
	point->x = sqrt(2) / 2 * (x - point->y);
	point->y = 1 / sqrt(3) * (x + point->y - point->z);
}

void	transform_cab(t_point *point)
{
	point->x = point->x - point->z * -cos(M_PI / 4);
	point->y = point->y - point->z * sin(M_PI / 4);
}
