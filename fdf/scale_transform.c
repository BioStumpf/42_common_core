/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:37:28 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/02 09:43:07 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_iso(t_point *grid_row, int x, int y)
{
	grid_row[x].x_iso = (sqrt(2) / 2) * (x + grid_row[x].z);
	grid_row[x].y_iso = sqrt(2.0 / 3) * (0.5 * x + y - 0.5 * grid_row[x].z);
}
