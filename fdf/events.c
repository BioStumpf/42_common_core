/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/24 16:38:47 by dstumpf          ###   ########.fr       */
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

static void	mouse_clicked(int x, int y, t_data *data, bool *button)
{
	*button = true;
	data->mouse->x_last = x;
	data->mouse->y_last = y;
}

static int	mouse_release(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	if (button == 1)
		data->mouse->left = false;
	return (0);
}

static int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mouse->left)
	{
		data->grid->offset_x += x - data->mouse->x_last;
		data->grid->offset_y += y - data->mouse->y_last;
	}
	data->mouse->x_last = x;
	data->mouse->y_last = y;
	return (0);
}

static void	mouse_zoom(int button, int x, int y, t_data *data)
{
	double	factor;

	if (button == 4)
		factor = 1.1;
	else
		factor = 0.9;
	data->grid->offset_x = x - (x - data->grid->offset_x) * factor;
    data->grid->offset_y = y - (y - data->grid->offset_y) * factor;
    data->grid->zoom *= factor;
}

static int	mouse_press(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 1)
		mouse_clicked(x, y, data, &data->mouse->left);
	else if (button == 4 || button == 5)
		mouse_zoom(button, x, y, data);
	else if (button == 3)
		data->img->color = (data->img->color + 1) % 3 + 3;
	return (0);
}

static int	key_press(int keysym, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	if (keysym == XK_w)
		data->grid->x_angle += 0.05;
	if (keysym == XK_s)
		data->grid->x_angle -= 0.05;
	if (keysym == XK_e)
		data->grid->y_angle += 0.05;
	if (keysym == XK_q)
		data->grid->y_angle -= 0.05;
	if (keysym == XK_d)
		data->grid->z_angle += 0.05;
	if (keysym == XK_a)
		data->grid->z_angle -= 0.05;
	if (keysym == XK_r || keysym == XK_c || keysym == XK_i)
	{
		data->grid->def_view = true;
		data->grid->z_scale = 1;
	}
	if (keysym == XK_c)
		data->grid->project = transform_cav;
	if (keysym == XK_i)
		data->grid->project = transform_iso;
	if (keysym == XK_Up)
		data->grid->z_scale += 0.1;
	if (keysym == XK_Down)
		data->grid->z_scale -= 0.1;
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
	mlx_hook(data->win, 2, 1L<<0, &key_press, data);
	mlx_hook(data->win, 17, 0, mlx_loop_end, data->mlx);
	mlx_expose_hook(data->win, draw_img, data);
	mlx_mouse_hook(data->win, mouse_press, data);
	mlx_hook(data->win, 5, 1L<<3, mouse_release, data);
	mlx_hook(data->win, 6, 1L<<6, mouse_move, data);
	mlx_loop_hook(data->mlx, draw_img, data);
}
