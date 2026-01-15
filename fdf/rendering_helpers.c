/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:42:41 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/14 16:40:23 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	make_img(t_data *data, t_imge *img, t_grid *grid)
{
	int	width;
	int	height;

	width = grid->x_range.max - grid->x_range.min + 1;
	height = grid->y_range.max - grid->y_range.min + 1;
	img->img = mlx_new_image(data->mlx, width, height);
	if (!img->img)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->len, &img->end);
	img->bytes = img->bits / 8;
	return (0);
}

void	pixel_to_img(t_imge *img, int x, int y, uint64_t color)
{
	char	*pixel_addr;
	int		i;

	pixel_addr = img->addr + (y * img->len + x * img->bytes);
	i = -1;
	while (++i < img->bytes)
		pixel_addr[i] = (color >> (8 * i)) & 0xFF;
}

void	free_mlx(t_data *data)
{
	if (!data->mlx)
		return ;
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return ;
	}
	if (!data->img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return ;
	}
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
