/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:54:14 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/25 12:18:38 by dstumpf          ###   ########.fr       */
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
# include <mlx.h>
# include <X11/keysym.h>

# define WIDTH 1000 
# define HEIGHT 800 
# define LOWEST 0x0000FF
# define HIGHEST 0xFF0000
# define INTERPOLATE 3
# define ZSCALE 4
# define USER 5

typedef struct s_mouse
{
	bool	left;
	int		x_last;
	int		y_last;
}			t_mouse;

typedef struct s_imge
{
	void	*img;
	char	*addr;
	int		bits;
	int		bytes;
	int		len;
	int		end;
	int		color;
}			t_imge;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		icolor;
	int		zcolor;
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
	double	zoom;
	double	z_scale;
	int		offset_x;
	int		offset_y;
	void	(*project)(t_point *point);
	bool	def_view;
	t_point	**mat;
}			t_grid;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_imge	*img;
	t_grid	*grid;
	t_mouse	*mouse;
}			t_data;

//error parsing
void	exit_error(const char *message, int errnum);
void	exit_lsterror(t_list *map_lst, int fd, int errnum);
void	exit_griderror(t_grid *grid, t_list *map_lst, int errnum);
void	exit_mlxerror(t_data *data, t_grid *grid);
//utils for linked list and grid
void	free_grid(t_grid *grid);
t_grid	*make_grid(t_list *map_lst);
t_list	*read_map_lst(int fd);
void	grid_apply(t_data *data, void (*f)(t_data *data, int x, int y));
//bringing the grid to the screen/ rendering/ displaying
void	display_grid(t_grid *grid);
int		make_img(t_data *data, t_imge *img);
void	pixel_to_img(t_imge *img, int x, int y, uint64_t color);
void	grid_to_img(t_imge *mlx_img, t_grid *grid);
void	free_mlx(t_data *data);
//math helpers
void	rotate_x(t_point *point, double angle, double center_y);
void	rotate_y(t_point *point, double angle, double center_x);
void	rotate_z(t_point *point, double angle, double center_x, double center_y);
void	transform_iso(t_point *point);
void	transform_cav(t_point *point);
void	scale_points(t_data *data);
//event functions   
void	attach_hooks(t_data *data);
//line drawing and color gradient
void	lines_to_img(t_data *data, int x, int y);
//color functions
void	scale_color(t_grid *grid, t_point *point);
int		fetch_color(t_imge *img, t_point *a, t_point *b, double r);


#endif
