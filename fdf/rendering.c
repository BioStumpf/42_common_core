/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:26:17 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/03 18:58:22 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grid_to_img(t_my_img *mlx_img, t_grid *grid)
{
	double	scale;
	double	x_scaled;
	double	y_scaled;
	int		i;
	int		j;

	i = -1;
	scale = find_scale_factor(grid);
	while (++i < grid->rows)
	{
		j = -1;
		while (++j < grid->cols)
		{
			x_scaled = (grid->mat[i][j].x_iso - grid->x_min) * scale;
			y_scaled = (grid->mat[i][j].y_iso - grid->y_min) * scale;
			pixel_to_img(mlx_img, (int)x_scaled, (int)y_scaled, 0xFFFFFFFF);
		}
	}
}

void	free_mlx(void *mlx, void *mlx_win, t_my_img *mlx_img)
{
	mlx_destroy_image(mlx, mlx_img->img);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}

void	display_grid(t_grid *grid)
{
	void		*mlx;
	void		*mlx_win;
	t_my_img	mlx_img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hey there!");
	make_img(mlx, &mlx_img);	
	grid_to_img(&mlx_img, grid);
	mlx_put_image_to_window(mlx, mlx_win, mlx_img.img, 0, 0);
	mlx_loop(mlx);
	free_mlx(mlx, mlx_win, &mlx_img);
}
