/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:26:17 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/13 16:24:53 by dstumpf          ###   ########.fr       */
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

void	free_mlx(t_mlx_dat *mlx)
{
	if (!mlx->dis)
		return ;
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->dis);
		free(mlx->dis);
		return ;
	}
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->dis, mlx->win);
		mlx_destroy_display(mlx->dis);
		free(mlx->dis);
		return ;
	}
	mlx_destroy_image(mlx->dis, mlx->img->img);
	mlx_destroy_window(mlx->dis, mlx->win);
	mlx_destroy_display(mlx->dis);
	free(mlx->dis);
}

void	display_grid(t_grid *grid)
{
	t_mlx_dat	mlx;
	t_imge		img;
	int			offset_x;
	int			offset_y;

	mlx.img = &img;
	offset_x = (WIDTH - (grid->x_max - grid->x_min)) / 2;
	offset_y = (HEIGHT - (grid->y_max - grid->y_min)) / 2;
	mlx.dis = mlx_init();
	if (!mlx.dis)
		exit_mlxerror(&mlx, grid);
	mlx.win = mlx_new_window(mlx.dis, WIDTH, HEIGHT, "Fdf");
	if (!mlx.win)
		exit_mlxerror(&mlx, grid);
	if ((make_img(&mlx, &img, grid) == -1))
		exit_mlxerror(&mlx, grid);
	grid_to_img(&img, grid);
	mlx_put_image_to_window(mlx.dis, mlx.win, img.img, offset_x, offset_y);
	mlx_key_hook(mlx.win, &handle_keyrelease, &mlx);
	mlx_loop(mlx.dis);
	mlx_destroy_display(mlx.dis);
	free(mlx.dis);
}
