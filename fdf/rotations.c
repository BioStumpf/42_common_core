/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:49:08 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/25 14:26:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *p, double angle, double center_y)
{
	double	y;

	if (angle == 0)
		return ;
	y = p->y - center_y;
	p->y = y * cos(angle) - p->z * sin(angle);
	p->z = y * sin(angle) + p->z * cos(angle);
	p->y += center_y;
}

void	rotate_y(t_point *p, double angle, double center_x)
{
	double	x;

	if (angle == 0)
		return ;
	x = p->x - center_x;
	p->x = x * cos(angle) + p->z * sin(angle);
	p->z = -x * sin(angle) + p->z * cos(angle);
	p->x += center_x;
}

void	rotate_z(t_point *p, double angle, double center_x, double center_y)
{
	double	x;
	double	y;

	if (angle == 0)
		return ;
	x = p->x - center_x;
	y = p->y - center_y;
	p->x = x * cos(angle) - y * sin(angle);
	p->y = x * sin(angle) + y * cos(angle);
	p->x += center_x;
	p->y += center_y;
}

void	transform_iso(t_point *p)
{
	double	x;

	x = p->x;
	p->x = sqrt(2) / 2 * (x - p->y);
	p->y = 1 / sqrt(3) * (x + p->y - p->z);
}

void	transform_cav(t_point *p)
{
	p->x = p->x - p->z * -cos(M_PI / 4);
	p->y = p->y - p->z * sin(M_PI / 4);
}
