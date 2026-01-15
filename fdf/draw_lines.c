/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:26:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/15 12:58:18 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	dda(t_point a, t_point b, t_imge *img)
{
	int		i;
	double	dx;
	double	dy;
	double	step;

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
		pixel_to_img(img, (int)round(a.x + i * dx), (int)round(a.y + i * dy), 0xFFFFFF);
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
