/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:39:29 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/28 17:56:34 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}

void	exit_lsterror(t_list *map_lst)
{
	ft_lstclear(map_lst, free);
	exit_error("Malloc failure during linked list generation!");
}

void	exit_griderror(t_grid *grid, t_list *map_lst)
{
	free_mat(grid);
	ft_lstclear(map_lst, free);
	exit_error("Malloc failure during grid generation!");
}
