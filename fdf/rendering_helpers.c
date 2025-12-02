/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:42:41 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/02 16:22:46 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_img(void *mlx, t_my_img *img)
{
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_get_data_addr(img->img, &img->bits_pp, &img->line_len, &img->endian);
	img->bytes_pp = img->bits_pp / 8;
}

void	my_pixel_put(t_my_img *img, int x, int y, uint64_t color)
{
	char	*pixel_addr;
	int		i;

	pixel_addr = img->addr + (y * img->line_len + x * img->bytes_pp);
	i = -1;
	while (++i < img->bytes_pp)
		pixel_addr[i] = (color >> (8 * i)) & 0xFF;
}
