/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:26:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/22 17:43:07 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	height_factor(double z, double z_min, double z_max)
{
	if (z_min == z_max)
		return (0.5);
	return ((z - z_min) / (z_max - z_min));
}

static int	interpolate_color(int ca, int cb, double r)
{
	int	red;
	int	green;
	int	blue;

	red = ((ca >> 16) & 0xFF) + r * (((cb >> 16) & 0xFF) - ((ca >> 16) & 0xFF));
	green = ((ca >> 8) & 0xFF) + r * (((cb >> 8) & 0xFF) - ((ca>> 8) & 0xFF));
	blue = (ca & 0xFF) + r * ((cb & 0xFF) - (ca & 0xFF));
	return (red << 16 | green << 8 | blue);
}

void	scale_color(t_data *data, int x, int y)
{
	t_grid	*grid;
	double	hf;
	int		height;

	grid = data->grid;
	hf = height_factor(grid->mat[y][x].z, grid->z_range.min, grid->z_range.max);
	height = interpolate_color(LOWEST, HIGHEST, hf);
	grid->mat[y][x].color = interpolate_color(height, grid->mat[y][x].color, 0.5);
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
		color = interpolate_color(a.color, b.color, i / step); 
		pixel_to_img(img, (int)round(a.x + i * dx), (int)round(a.y + i * dy), color);
	}
}

static void	zoom_and_translate(t_point *point, t_grid *grid)
{
	point->x = point->x * grid->zoom + grid->offset_x;
	point->y = point->y * grid->zoom + grid->offset_y;
}

static void	transform_point(t_point *point, t_grid *grid)
{
	double	center_x;
	double	center_y;

	center_x = grid->cols / 2;
	center_y = grid->rows / 2;
	rotate_x(point, grid->x_angle, center_y);
	rotate_y(point, grid->y_angle, center_x);
	rotate_z(point, grid->z_angle, center_x, center_y);
	transform_iso(point);
	zoom_and_translate(point, grid);
}

void	lines_to_img(t_data *data, int x, int y)
{
	t_point p;
	t_point p_next;

	p = data->grid->mat[y][x];
	transform_point(&p, data->grid);
	if (x + 1 < data->grid->cols)
	{
		p_next = data->grid->mat[y][x + 1];
		transform_point(&p_next, data->grid);
		dda(p, p_next, data->img);
	}
	if (y + 1 < data->grid->rows)
	{
		p_next = data->grid->mat[y + 1][x];
		transform_point(&p_next, data->grid);
		dda(p, p_next, data->img);
	}
}
