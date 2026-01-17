/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:54:14 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/16 14:44:33 by dstumpf          ###   ########.fr       */
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
# include <X11/keysym.h>

# define WIDTH 600 
# define HEIGHT 500 
//# define LOWEST 0x0000FF
//# define HIGHEST 0xFF0000

typedef struct s_imge
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits;
	int		bytes;
	int		len;
	int		end;
}			t_imge;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_point;

typedef struct s_range
{
	double	min;
	double	max;
}			t_range;

typedef struct s_grid
{
	int		rows;
	int		cols;
	t_range	x_range;
	t_range	y_range;
	t_range	z_range;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	t_point	**mat;
}			t_grid;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_imge	*img;
	t_grid	*grid;
}			t_data;

//error parsing
void	exit_error(const char *message, int errnum);
void	exit_lsterror(t_list *map_lst, int fd, int errnum);
void	exit_griderror(t_grid *grid, t_list *map_lst, int errnum);
void	exit_mlxerror(t_data *data, t_grid *grid);
//parsing utils for linked list and grid
void	free_grid(t_grid *grid);
t_grid	*make_grid(t_list *map_lst);
t_list	*read_map_lst(int fd);
void	grid_apply(t_data *data, void (*f)(t_data *data, int x, int y));
//bringing the grid to the screen/ rendering/ displaying
void	display_grid(t_grid *grid);
int		make_img(t_data *data, t_imge *img, t_grid *grid);
void	pixel_to_img(t_imge *img, int x, int y, uint64_t color);
void	grid_to_img(t_imge *mlx_img, t_grid *grid);
void	free_mlx(t_data *data);
//math helpers
void	rotate_x(t_point *point, double angle);
void	rotate_y(t_point *point, double angle);
void	rotate_z(t_point *point, double angle);
void	transform_iso(t_point *point);
void	set_grid_range(t_grid *grid, int col, t_point *point);
//double	find_scale_factor(t_grid *grid);
void	scale_points(t_grid *grid);
//event functions
void	attach_hooks(t_data *data);
//line drawing and color gradient
void	lines_to_img(t_data *data, int x, int y);
//void	scale_color(t_data *data, int x, int y);

#endif
