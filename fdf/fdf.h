/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:54:14 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/02 09:38:13 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_point
{
	double	x_iso;
	double	y_iso;
	int		z;
}			t_point;

typedef struct s_grid
{
	int		rows;
	int		cols;
	t_point	**mat;
}			t_grid;

void	exit_error(const char *message, int errnum);
void	exit_lsterror(t_list *map_lst, int errnum);
void	exit_griderror(t_grid *grid, t_list *map_lst, int errnum);
void	free_grid(t_grid *grid);
t_grid	*make_grid(t_list *map_lst);
t_list	*read_map_lst(int fd);
void	transform_iso(t_point *grid_row, int x, int y);

#endif
