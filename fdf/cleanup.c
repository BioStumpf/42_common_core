/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:54:27 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/25 11:47:58 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_grid(t_grid *grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid->mat && i < grid->rows)
		free(grid->mat[i++]);
	free(grid->mat);
	free(grid);
}

void	free_mlx(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img->img)
		mlx_destroy_image(data->mlx, data->img->img);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
