/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_loop_events.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/26 17:37:32 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_img(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_bzero(data->img->addr, data->img->len * HEIGHT);
	if (data->grid->def_view)
	{
		data->grid->x_angle = 0;
		data->grid->y_angle = 0;
		data->grid->z_angle = 0;
		data->grid->def_view = false;
		scale_points(data);
	}
	grid_apply(data, lines_to_img);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

static int	key_press(int keysym, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	if (keysym == XK_r || keysym == XK_c || keysym == XK_i)
	{
		data->grid->def_view = true;
		data->grid->z_scale = 1;
	}
	if (keysym == XK_c)
		data->grid->project = transform_cav;
	if (keysym == XK_i)
		data->grid->project = transform_iso;
	data->grid->x_angle += (keysym == XK_w) * 0.05 - (keysym == XK_s) * 0.05;
	data->grid->y_angle += (keysym == XK_e) * 0.05 - (keysym == XK_q) * 0.05;
	data->grid->z_angle += (keysym == XK_d) * 0.05 - (keysym == XK_a) * 0.05;
	data->grid->z_scale += (keysym == XK_Up) * 0.1 - (keysym == XK_Down) * 0.1;
	return (0);
}

//2 = KeyPress
//5 = ButtonRelease
//6 = PointerMove
//17 = DestroyNotify
//mouse_hook = ButtonPress

void	attach_hooks(t_data *data)
{
	data->mouse->left = false;
	data->grid->z_scale = 1;
	mlx_hook(data->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win, 17, 0, mlx_loop_end, data->mlx);
	mlx_mouse_hook(data->win, mouse_press, data);
	mlx_hook(data->win, 5, 1L << 3, mouse_release, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move, data);
	mlx_loop_hook(data->mlx, draw_img, data);
}
