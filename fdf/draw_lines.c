/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:26:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/16 15:40:19 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_color(t_data data, int x, int y)
{
	t_grid	*grid;
	int		z;
	int		min;
	int		max;

	grid = data->grid;
	z = grid->mat[x][y].z;
	min = grid->z_range.min;
	max = grid->z_range.max;
	grid->mat[x][y].color = LOWEST (z - min) * (max - min);
	grid->mat[x][y].color = LOWEST (z - min) * (max - min);
}

static int	interpolate_color(t_point *a, t_point *b, double ratio)
{
	int	red;
	int	green;
	int	blue;

	red = ((a->color >> 16) & 0xFF) + ratio * (((b->color >> 16) & 0xFF)- ((a->color >> 16) & 0xFF));
	green = ((a->color >> 8) & 0xFF) + ratio * (((b->color >> 8) & 0xFF) - ((a->color >> 8) & 0xFF));
	blue = (a->color & 0xFF) + ratio * ((b->color & 0xFF) - (a->color & 0xFF));
	return (red << 16 | green << 8 | blue);
}

static void	dda(t_point a, t_point b, t_imge *img)
{
	double	dx;
	double	dy;
	double	step;
	int		color;
	int		i;

	dx = b.x - a.x;
	dy = b.y - a.y;
	step = fmax(fabs(dx), fabs(dy));
	if (step == 0)
	{
		pixel_to_img(img, a.x, a.y, 0xFFFFFF);
		return ;
	}
	dx = dx / step;
	dy = dy / step;
	i = -1;
	while (++i <= step)
	{
		color = interpolate_color(&a, &b, i / step); 
		pixel_to_img(img, (int)round(a.x + i * dx), (int)round(a.y + i * dy), color);
	}
}

void	draw_point_line(t_data *data, int x, int y)
{
	t_grid	*grid;
	
	grid = data->grid;
	if (x + 1 < grid->cols)
		dda(grid->mat[y][x], grid->mat[y][x + 1], data->img);
	if (y + 1 < grid->rows)
		dda(grid->mat[y][x], grid->mat[y + 1][x], data->img);
}
