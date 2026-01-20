/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/20 18:23:52 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_img(t_data *data)
{
	grid_apply(data, lines_to_img);	
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

static int	handle_mouse(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	//if (button == 1)
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

void	attach_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L<<0, &handle_key, data);
	//mlx_key_hook(data->win, &handle_keyrelease, data);
	mlx_hook(data->win, 17, 0, mlx_loop_end, data->mlx);
	mlx_expose_hook(data->win, draw_img, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	//mlx_mouse_show(data->mlx, data->win);
}
