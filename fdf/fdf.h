/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:54:14 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/03 18:58:05 by dstumpf          ###   ########.fr       */
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
# include "mlx.h"

# define WIDTH 40 
# define HEIGHT 40 

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
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	t_point	**mat;
}			t_grid;

typedef struct s_my_img
{
	void	*img;
	char	*addr;
	int		bits_pp;
	int		bytes_pp;
	int		line_len;
	int		endian;
}			t_my_img;

//error parsing
void	exit_error(const char *message, int errnum);
void	exit_lsterror(t_list *map_lst, int fd, int errnum);
void	exit_griderror(t_grid *grid, t_list *map_lst, int errnum);
//parsing utils for linked list and grid
void	free_grid(t_grid *grid);
t_grid	*make_grid(t_list *map_lst);
t_list	*read_map_lst(int fd);
//math/transformation
void	transform_iso(t_point *grid_row, int x, int y);
//bringing the grid to the screen/ rendering/ displaying
void	display_grid(t_grid *grid);
void	make_img(void *mlx, t_my_img *img);
void	pixel_to_img(t_my_img *img, int x, int y, uint64_t color);
void	grid_to_img(t_my_img *mlx_img, t_grid *grid);
void	set_min_max(t_grid *grid, t_point *point);
double	find_scale_factor(t_grid *grid);

#endif
