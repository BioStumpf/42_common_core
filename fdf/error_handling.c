/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:39:29 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/02 11:47:26 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(const char *message, int errnum)
{
	errno = errnum;
	perror(message);
	exit(1);
}

void	exit_lsterror(t_list *map_lst, int errnum)
{
	ft_lstclear(map_lst, free);
	if (errnum == EINVAL)
		exit_error("Map is not valid.", errnum);
	else
		exit_error("Failed to read map.", errnum);
}

void	exit_griderror(t_grid *grid, t_list *map_lst, int errnum)
{
	ft_lstclear(map_lst, free);
	free_grid(grid);
	if (errnum == EINVAL)
		exit_error("Map is not valid.", errnum);
	else
		exit_error("Failed to read map.", errnum);
}
