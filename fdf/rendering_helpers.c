/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:42:41 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/03 15:18:13 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_img(void *mlx, t_imge *img)
{
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->len, &img->end);
	img->bytes = img->bits / 8;
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
