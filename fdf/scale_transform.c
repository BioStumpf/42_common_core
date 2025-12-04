/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:37:28 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/03 18:43:08 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_min_max(t_grid *grid, t_point *point)
{
	if (point->x > grid->x_max)
		grid->x_max = point->x;
	if (point->x < grid->x_min)
		grid->x_min = point->x;
	if (point->y > grid->y_max)
		grid->y_max = point->y;
	if (point->y < grid->y_min)
		grid->y_min = point->y;
}

void	transform_iso(t_point *grid_row, int col)
{
	rotate_z(&grid_row[col], M_PI / 4);
	rotate_x(&grid_row[col], atan(1 / sqrt(2)));
	//grid_row[x].x = (sqrt(2) / 2) * (x - y);
	//grid_row[x].y = 1 / sqrt(3) * (x + y + grid_row[x].z);
//	grid_row[col].x = (sqrt(2) / 2) * (grid_row[col].x + grid_row[col].z);
//	grid_row[col].y = sqrt(2.0 / 3) * (0.5 * grid_row[col].x + grid_row[col].y - 0.5 * grid_row[col].z);
}

double	find_scale_factor(t_grid *grid)
{
	double	x_diff;
	double	y_diff;
	double	x_scale;
	double	y_scale;

	x_diff = grid->x_max - grid->x_min;
	y_diff = grid->y_max - grid->y_min;
	x_scale = IMG_W;
	y_scale = IMG_H;
	if (x_diff != 0)
		x_scale = x_scale / x_diff; 
	if (y_diff != 0)
		y_scale = x_scale / y_diff;
	if (x_scale <= y_scale)
		return (x_scale);
	else
		return (y_scale);
}

void	scale_points(t_grid *grid)
{
	double	scale;
	double	mid_x;
	double	mid_y;
	int		row;
	int		col;

	scale = find_scale_factor(grid);
	row = -1;
	while (++row < grid->rows)
	{
		col = -1;
		while (++col < grid->cols)
		{
			mid_x = 0.5 * (grid->x_max - grid->x_min);
			mid_y = 0.5 * (grid->y_max - grid->y_min);
			grid->mat[row][col].x = (grid->mat[row][col].x - grid->x_min + mid_x) * scale;
			grid->mat[row][col].y = (grid->mat[row][col].y - grid->y_min + mid_y) * scale;
		}
	}
}	
