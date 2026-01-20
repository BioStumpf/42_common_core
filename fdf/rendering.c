/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:26:17 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/20 14:28:26 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int	make_img(t_data *data, t_imge *img, t_grid *grid)
int	make_img(t_data *data, t_imge *img)
{
	//scale_points(grid);
	//img->width = grid->x_range.max - grid->x_range.min + 2;
	//img->height = grid->y_range.max - grid->y_range.min + 2;
	//img->img = mlx_new_image(data->mlx, img->width, img->height);
	//if (!img->img)
	//	return (-1);
	//img->addr = mlx_get_data_addr(img->img, &img->bits, &img->len, &img->end);
	//img->bytes = img->bits / 8;
	//return (0);
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
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

	//if (x < 0 || x > img->width || y < 0 || y > img->height)
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel_addr = img->addr + (y * img->len + x * img->bytes);
	i = -1;
	while (++i < img->bytes)
		pixel_addr[i] = (color >> (8 * i)) & 0xFF;
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
	//if ((make_img(&data, &img, grid) == -1))
	if ((make_img(&data, &img) == -1))
		exit_mlxerror(&data, grid);
//	grid_apply(&data, refine_coordinates);
	scale_points(&data);
//	draw_img(&data);
//	grid_apply(&data, scale_color);
	attach_hooks(&data);
	mlx_loop(data.mlx);
	free_mlx(&data);
}
