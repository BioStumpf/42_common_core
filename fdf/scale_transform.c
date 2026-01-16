/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:37:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/16 14:43:56 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_range(t_range *range, double min, double max)
{
	range->min = min;
	range->max = max;
}

static void	expand_range(t_range *range, double val)
{
	if (val > range->max)
		range->max = val;
	else if (val < range->min)
		range->min = val;
}

void	set_grid_range(t_grid *grid, int col, t_point *point)
{
	if (grid->rows == 0 && col == 0)
	{
		set_range(&grid->x_range, point->x, point->x);
		set_range(&grid->y_range, point->y, point->y);
		set_range(&grid->z_range, point->z, point->z);
		return ;
	}
	expand_range(&grid->x_range, point->x);
	expand_range(&grid->y_range, point->y);
	expand_range(&grid->z_range, point->z);
}

static double	find_scale_factor(t_grid *grid)
{
	double	x_diff;
	double	y_diff;
	double	x_scale;
	double	y_scale;

	x_diff = grid->x_range.max - grid->x_range.min;
	y_diff = grid->y_range.max - grid->y_range.min;
	x_scale = WIDTH * 0.8;
	y_scale = HEIGHT * 0.8;
	if (x_diff != 0)
		x_scale = x_scale / x_diff;
	if (y_diff != 0)
		y_scale = y_scale / y_diff;
	if (x_scale <= y_scale)
		return (x_scale);
	return (y_scale);
}

void	scale_points(t_grid *grid)
{
	double	scale;
	int		row;
	int		col;
	double	x_min;
	double	y_min;
	double	z_min;

	scale = find_scale_factor(grid);
	row = -1;
	x_min = grid->x_range.min;
	y_min = grid->y_range.min;
	z_min = grid->z_range.min;
	while (++row < grid->rows)
	{
		col = -1;
		while (++col < grid->cols)
		{
			grid->mat[row][col].x = (grid->mat[row][col].x - x_min) * scale;
			grid->mat[row][col].y = (grid->mat[row][col].y - y_min) * scale;
			grid->mat[row][col].z = (grid->mat[row][col].z - z_min) * scale;
		}
	}
	set_range(&grid->x_range, 0, (grid->x_range.max - x_min) * scale);
	set_range(&grid->y_range, 0, (grid->y_range.max - y_min) * scale);
	set_range(&grid->z_range, 0, (grid->z_range.max - z_min) * scale);
}
