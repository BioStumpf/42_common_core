/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:30:38 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/28 18:17:23 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mat(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->rows)
		free(grid->mat[i++]);
	free(grid);
}
