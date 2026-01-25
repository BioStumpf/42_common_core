/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:01:07 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/25 14:05:12 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void	mouse_clicked(int x, int y, t_data *data, bool *button)
{
	*button = true;
	data->mouse->x_last = x;
	data->mouse->y_last = y;
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	if (button == 1)
		data->mouse->left = false;
	return (0);
}

int	mouse_move(int x, int y, void *param)
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

int	mouse_press(int button, int x, int y, void *param)
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
