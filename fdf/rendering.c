/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:26:17 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/14 12:29:33 by dstumpf          ###   ########.fr       */
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

void	display_grid(t_grid *grid)
{
	t_data	data;
	t_imge	img;

	data.img = &img;
	data.grid = grid;
	data.mlx = mlx_init();
	if (!data.mlx)
		exit_mlxerror(&data, grid);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fdf");
	if (!data.win)
		exit_mlxerror(&data, grid);
	if ((make_img(&data, &img, grid) == -1))
		exit_mlxerror(&data, grid);
	attach_hooks(&data);
	mlx_loop(data.mlx);
	free_mlx(&data);
}
