/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/13 15:31:45 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keyrelease(int keysym, t_mlx_dat *mlx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(mlx->dis, mlx->img->img);
		mlx_destroy_window(mlx->dis, mlx->win);
		mlx_loop_end(mlx->dis);
	}
	return (0);
}
