/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:54:14 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/28 17:38:16 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_point
{
	int	x_iso;
	int	y_iso;
	int	z;
}		t_point;

typedef struct s_grid
{
	int		rows;
	int		cols;
	t_point	**mat;
}			t_grid;

void	exit_error(char *message);
void	exit_lsterror(t_list *map_lst);
t_list	*read_map_lst(int fd);

#endif
