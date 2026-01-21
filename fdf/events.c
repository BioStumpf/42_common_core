/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/21 16:00:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_img(t_data *data)
{
	grid_apply(data, lines_to_img);	
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

static void	mouse_left(int x, int y, t_data *data)
{
	data->mouse->pressed = true;
	data->mouse->x_last = x;
	data->mouse->y_last = y;
}

static int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->mouse->pressed = false;
	return (0);
}

static int	mouse_move(int x, int y, t_data	*data)
{
	if (data->mouse->pressed)
	{
		data->grid->offset_x += x - data->mouse->x_last;
		data->grid->offset_y += y - data->mouse->y_last;
		data->mouse->x_last = x;
		data->mouse->y_last = y;
		ft_bzero(data->img->addr, data->img->len * HEIGHT);
		draw_img(data);
	}
	return (0);
}

static int	handle_mouse(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{ 
		mouse_left(x, y, data);
		return (0); 
	}
	if (button == 4)
		data->grid->zoom += 0.1 * data->grid->zoom;
	else if (button == 5)
		data->grid->zoom -= 0.1 * data->grid->zoom;
	ft_bzero(data->img->addr, data->img->len * HEIGHT);
	draw_img(data);
	return (0);
}

static int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx);
		return (0);
	}
	ft_bzero(data->img->addr, data->img->len * HEIGHT);
	if (keysym == XK_1)
		data->grid->z_angle += 0.05;
	else if(keysym == XK_2)
		data->grid->z_angle -= 0.05;
	else if(keysym == XK_7)
		data->grid->y_angle += 0.05;
	else if(keysym == XK_8)
		data->grid->y_angle -= 0.05;
	else if(keysym == XK_4)
		data->grid->x_angle += 0.05;
	else if(keysym == XK_5)
		data->grid->x_angle -= 0.05;
	draw_img(data);
	return (0);
}

//2 = KeyPress
//5 = ButtonRelease
//6 = PointerMove
//17 = DestroyNotify

void	attach_hooks(t_data *data)
{
	t_mouse mouse;

	data->mouse = &mouse;
	mlx_hook(data->win, 2, 1L<<0, &handle_key, data);
	mlx_hook(data->win, 17, 0, mlx_loop_end, data->mlx);
	mlx_expose_hook(data->win, draw_img, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_hook(data->win, 5, 1L<<3, mouse_release, data);
	mlx_hook(data->win, 6, 1L<<6, mouse_move, data);
	//mlx_mouse_show(data->mlx, data->win);
	//mlx_key_hook(data->win, &handle_keyrelease, data);
}
