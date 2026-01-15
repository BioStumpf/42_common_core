/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_grid_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:30:38 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/15 12:57:46 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	extract_color(char **line)
{
	int	color;

	if (**line && !ft_strncmp((*line), ",0x", 3))
	{
		(*line) += 2;
		color = ft_atoi_hex_multi(line);
	}
	else
		color = 0xFFFFFF;
	return (color);
}

static void	set_grid_point(char **line, t_point *point, int row, int col)
{
	point->z = ft_atoi_multi(line);
	point->x = col;
	point->y = row;
	point->color = extract_color(line);
}

static t_point	*make_grid_row(void *line, t_grid *grid, t_list *map_lst)
{
	t_point	*grid_row;
	char	*line_cpy;
	int		col_count;
	int		col;

	col_count = (int)count_words(line, " \t\n\v\f\r");
	if (grid->rows == 0)
		grid->cols = col_count;
	if (col_count <= 0 || col_count != grid->cols)
		exit_griderror(grid, map_lst, EINVAL);
	grid_row = malloc(sizeof(t_point) * col_count);
	if (!grid_row)
		exit_griderror(grid, map_lst, ENOMEM);
	col = -1;
	line_cpy = (char *)line;
	while (++col < grid->cols && *line_cpy)
	{
		set_grid_point(&line_cpy, &grid_row[col], grid->rows, col);
		transform_iso(&grid_row[col]);
		set_grid_range(grid, col, &grid_row[col]);
	}
	if (col != grid->cols)
		exit_griderror(grid, map_lst, EINVAL);
	return (grid_row);
}

t_grid	*make_grid(t_list *map_lst)
{
	t_grid	*grid;
	t_node	*cursor;

	grid = malloc(sizeof(t_grid));
	if (!grid)
		exit_griderror(grid, map_lst, ENOMEM);
	grid->mat = malloc(sizeof(t_point *) * map_lst->len);
	if (!grid->mat)
		exit_griderror(grid, map_lst, ENOMEM);
	cursor = map_lst->head;
	grid->rows = 0;
	while (grid->rows < (int)map_lst->len)
	{
		grid->mat[grid->rows] = make_grid_row(cursor->content, grid, map_lst);
		cursor = cursor->next;
		grid->rows++;
	}
	return (grid);
}

//used later to change values inside the grid
//data is the struct containing the grid amongst other info (data->grid)
//x and y are col and row of the grid that are used/ changed inside func
void	grid_apply(t_data *data, void (*f)(t_data *data, int x, int y))
{
	int		x;
	int		y;
	t_grid	*grid;

	grid = data->grid;
	x = -1;
	while (++x < grid->cols)
	{
		y = -1;
		while (++y < grid->rows)
			f(data, x, y);
	}
}

