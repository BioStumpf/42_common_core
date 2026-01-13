/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:42:41 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/13 16:25:34 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	make_img(t_mlx_dat *mlx, t_imge *img, t_grid *grid)
{
	int	width;
	int	height;

	width = grid->x_max - grid->x_min + 1;
	height = grid->y_max - grid->y_min + 1;
	img->img = mlx_new_image(mlx->dis, width, height);
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
