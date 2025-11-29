/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:39:29 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/29 15:22:05 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(const char *message)
{
	perror(message);
	exit(1);
}

void	exit_lsterror(t_list *map_lst)
{
	ft_lstclear(map_lst, free);
	errno = ENOMEM;
	exit_error("Failed to read map.");
}

void	exit_griderror(t_grid *grid, t_list *map_lst)
{
	ft_lstclear(map_lst, free);
	free_grid(grid);
	if (errno = EINVAL)
		exit_error("Map is not rectengular!");
	else
		exit_error("Failed to read map.");
}
