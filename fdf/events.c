/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/19 19:58:33 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_img(t_data *data)
{
	//int		off_x;
	//int		off_y;

	//off_x = (WIDTH - (data->grid->x_range.max - data->grid->x_range.min)) / 2;
	//off_y = (HEIGHT - (data->grid->y_range.max - data->grid->y_range.min)) / 2;
	//this is where the following things need to happen:
	//for each point, apply rotations, zoom, translation
	//then make it isometric
	//then plot the lines in between
	grid_apply(data, lines_to_img);	
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

static int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	else if (keysym == XK_z)
	{
		//ft_bzero(data->img->addr, data->img->len * data->img->width);
		ft_bzero(data->img->addr, data->img->len * HEIGHT);
		data->grid->z_angle += 0.05;
		draw_img(data);
	}
	return (0);
}

void	attach_hooks(t_data *data)
{
	mlx_key_hook(data->win, &handle_keyrelease, data);
	mlx_hook(data->win, 17, 0, mlx_loop_end, data->mlx);
	mlx_expose_hook(data->win, draw_img, data);
	//mlx_mouse_show(data->mlx, data->win);
}
