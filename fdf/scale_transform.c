/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:37:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/25 14:35:35 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	expand_range(t_range *range, double val)
{
	if (val > range->max)
		range->max = val;
	else if (val < range->min)
		range->min = val;
}

static void	set_grid_range(t_grid *grid, int col, int row, t_point *p)
{
	if (row == 0 && col == 0)
	{
		grid->x_range = (t_range){p->x, p->x};
		grid->y_range = (t_range){p->y, p->y};
		grid->z_range = (t_range){p->z, p->z};
		return ;
	}
	expand_range(&grid->x_range, p->x);
	expand_range(&grid->y_range, p->y);
	expand_range(&grid->z_range, p->z);
}

static double	find_scale_factor(t_grid *grid)
{
	double	x_diff;
	double	y_diff;
	double	x_scale;
	double	y_scale;

	x_diff = grid->x_range.max - grid->x_range.min;
	y_diff = grid->y_range.max - grid->y_range.min;
	x_scale = 0.8 * WIDTH;
	y_scale = 0.8 * HEIGHT;
	if (x_diff != 0)
		x_scale = x_scale / x_diff;
	if (y_diff != 0)
		y_scale = y_scale / y_diff;
	if (x_scale <= y_scale)
		return (x_scale);
	return (y_scale);
}

static void	range_finder(t_data *data, int x, int y)
{
	t_point	p;

	p = data->grid->mat[y][x];
	data->grid->project(&p);
	set_grid_range(data->grid, x, y, &p);
}

void	scale_points(t_data *data)
{
	t_range	*x_range;
	t_range	*y_range;
	double	zoom;

	grid_apply(data, range_finder);
	x_range = &data->grid->x_range;
	y_range = &data->grid->y_range;
	zoom = find_scale_factor(data->grid);
	data->grid->zoom = zoom;
	data->grid->offset_x = (WIDTH / 2.0) - \
	(zoom * ((x_range->max + x_range->min) / 2));
	data->grid->offset_y = (HEIGHT / 2.0) - \
	(zoom * ((y_range->max + y_range->min) / 2));
}
