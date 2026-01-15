/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/15 12:11:30 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	return (0);
}

static int	draw_img(t_data *data)
{
	int		off_x;
	int		off_y;

	off_x = (WIDTH - (data->grid->x_range.max - data->grid->x_range.min)) / 2;
	off_y = (HEIGHT - (data->grid->y_range.max - data->grid->y_range.min)) / 2;
	grid_apply(data, draw_point_line);	
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, off_x, off_y);
	return (0);
}

void	attach_hooks(t_data *data)
{
	mlx_key_hook(data->win, &handle_keyrelease, data);
	mlx_hook(data->win, 17, 0, mlx_loop_end, data->mlx);
	mlx_expose_hook(data->win, draw_img, data);
	//mlx_mouse_show(data->mlx, data->win);
}
