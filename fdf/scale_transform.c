/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:37:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/13 20:08:58 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//may be a bit confusing, but if we are at the first point, 
//we set all min/max values to those of that point
//everything after that is compared to the first point
void	set_min_max(t_grid *grid, int col, t_point *point)
{
	if (grid->rows == 0 && col == 0)
	{
		grid->x_max = point->x;
		grid->x_min = point->x;
		grid->y_max = point->y;
		grid->y_min = point->y;
		return ;
	}
	if (point->x > grid->x_max)
		grid->x_max = point->x;
	else if (point->x < grid->x_min)
		grid->x_min = point->x;
	if (point->y > grid->y_max)
		grid->y_max = point->y;
	else if (point->y < grid->y_min)
		grid->y_min = point->y;
}

void	transform_iso(t_point *point)
{
	rotate_z(point, M_PI / 4);
	rotate_x(point, atan(1 / sqrt(2)));
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
	x_scale = WIDTH * 0.8;
	y_scale = HEIGHT * 0.8;
	if (x_diff != 0)
		x_scale = x_scale / x_diff;
	if (y_diff != 0)
		y_scale = y_scale / y_diff;
	if (x_scale <= y_scale)
		return (x_scale);
	else
		return (y_scale);
}

//double	find_offset

void	scale_points(t_grid *grid)
{
	double	scale;
	int		row;
	int		col;

	scale = find_scale_factor(grid);
	row = -1;
	while (++row < grid->rows)
	{
		col = -1;
		while (++col < grid->cols)
		{
			//grid->mat[row][col].x = (grid->mat[row][col].x - grid->x_min) * scale + 0.25 * WIDTH;
			//grid->mat[row][col].y = (grid->mat[row][col].y - grid->y_min) * scale + 0.25 * HEIGHT;
			grid->mat[row][col].x = (grid->mat[row][col].x - grid->x_min) * scale;
			grid->mat[row][col].y = (grid->mat[row][col].y - grid->y_min) * scale;
		}
	}
	grid->x_max = (grid->x_max - grid->x_min) * scale;
	grid->x_min = (grid->x_min - grid->x_min) * scale;
	grid->y_max = (grid->y_max - grid->y_min) * scale;
	grid->y_min = (grid->y_min - grid->y_min) * scale;
}
