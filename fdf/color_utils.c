/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:10:47 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/25 14:29:04 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	height_factor(t_grid *grid, double z)
{
	double	z_min;
	double	z_max;

	z_min = grid->z_range.min * grid->z_scale;
	z_max = grid->z_range.max * grid->z_scale;
	if (z_min == z_max)
		return (0.5);
	else if (z_min > z_max)
		return ((z - z_max) / (z_min - z_max));
	else
		return ((z - z_min) / (z_max - z_min));
}

static int	interpolate_color(int ca, int cb, double r)
{
	int	red;
	int	green;
	int	blue;

	red = ((ca >> 16) & 0xFF) + r * (((cb >> 16) & 0xFF) - ((ca >> 16) & 0xFF));
	green = ((ca >> 8) & 0xFF) + r * (((cb >> 8) & 0xFF) - ((ca >> 8) & 0xFF));
	blue = (ca & 0xFF) + r * ((cb & 0xFF) - (ca & 0xFF));
	return (red << 16 | green << 8 | blue);
}

void	scale_color(t_grid *grid, t_point *p)
{
	double	hf;
	int		height;

	hf = height_factor(grid, p->z);
	height = interpolate_color(LOWEST, HIGHEST, hf);
	p->zcolor = height;
	p->icolor = interpolate_color(height, p->color, 0.5);
}

int	fetch_color(t_imge *img, t_point *a, t_point *b, double r)
{
	if (img->color == INTERPOLATE)
		return (interpolate_color(a->icolor, b->icolor, r));
	else if (img->color == ZSCALE)
		return (interpolate_color(a->zcolor, b->zcolor, r));
	else
		return (interpolate_color(a->color, b->color, r));
}
