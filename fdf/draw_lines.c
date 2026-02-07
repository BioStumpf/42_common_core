/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:26:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/07 13:37:06 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		color = fetch_color(img, &a, &b, 0.5);
		pixel_to_img(img, a.x, a.y, color);
		return ;
	}
	dx = dx / step;
	dy = dy / step;
	i = -1;
	while (++i <= step)
	{
		color = fetch_color(img, &a, &b, i / step);
		pixel_to_img(img, (int)round(a.x + i * dx),
			(int)round(a.y + i * dy), color);
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
	point->z *= grid->z_scale;
	scale_color(grid, point);
	rotate_x(point, grid->x_angle, center_y);
	rotate_y(point, grid->y_angle, center_x);
	rotate_z(point, grid->z_angle, center_x, center_y);
	grid->project(point);
	zoom_and_translate(point, grid);
}

void	lines_to_img(t_data *data, int x, int y)
{
	t_point	p;
	t_point	p_next;

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
