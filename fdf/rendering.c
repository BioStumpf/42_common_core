/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:26:17 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/12 12:58:12 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grid_to_img(t_imge *mlx_img, t_grid *grid)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = -1;
	while (++i < grid->rows)
	{
		j = -1;
		while (++j < grid->cols)
		{
			x = (int)grid->mat[i][j].x;
			y = (int)grid->mat[i][j].y;
			pixel_to_img(mlx_img, x, y, (uint64_t)grid->mat[i][j].color);
		}
	}
}

void	free_mlx(void *mlx, void *mlx_win, t_imge *mlx_img)
{
	mlx_destroy_image(mlx, mlx_img->img);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}

void	display_grid(t_grid *grid)
{
	void	*mlx;
	void	*mlx_win;
	t_imge	mlx_img;
	int		offset_x;
	int		offset_y;

	offset_x = (WIDTH - (grid->x_max - grid->x_min)) / 2;
	offset_y = (HEIGHT - (grid->y_max - grid->y_min)) / 2;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fdf");
	make_img(mlx, &mlx_img, grid);
	grid_to_img(&mlx_img, grid);
	mlx_put_image_to_window(mlx, mlx_win, mlx_img.img, offset_x, offset_y);
	mlx_loop(mlx);
	free_mlx(mlx, mlx_win, &mlx_img);
}
