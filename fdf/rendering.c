/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:26:17 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/02 16:21:54 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_grid(const t_grid *grid)
{
	void		*mlx;
	void		*mlx_win;
	t_my_img	mlx_img;

	(void )grid;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hey there!");
	make_img(mlx, &mlx_img);	
	my_pixel_put(&mlx_img, 8, 8, 0xFF);
	mlx_put_image_to_window(mlx, mlx_win, mlx_img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}
