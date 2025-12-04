/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_grid_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:30:38 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/03 18:59:55 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_grid(t_grid *grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid->mat && i < grid->rows)
		free(grid->mat[i++]);
	free(grid->mat);
	free(grid);
}

static t_grid	*init_grid(t_list *map_lst)
{
	t_grid	*grid;

	grid = malloc(sizeof(t_grid));
	if (!grid)
		exit_griderror(grid, map_lst, ENOMEM);
	grid->x_min = 0;
	grid->x_max = 0;
	grid->y_min = 0;
	grid->y_max = 0;
	grid->rows = 0;
	grid->cols = 0;
	grid->mat = NULL;
	return (grid);
}

static int	extract_color(char **line)
{
	(void)line;
	return (0xFFFFFF);
//	int	color;
//
//	if (**line && ft_strncmp(*line, ",0x", 3))
//	{
//		(*line) += 2;
//		color = ft_atoi_hex_multi(line);
//	}
//	else
//		color = 0xFFFFFF;
//	return (color);
}

static t_point	*make_grid_row(void *line, t_grid *grid, t_list *map_lst)
{
	t_point	*grid_row;
	char	*line_cpy;
	int		col_count;
	int		col;

	col_count = (int)count_words(line, ' ');
	if (grid->cols == 0)
		grid->cols = col_count;
	if (col_count <= 0 || col_count != grid->cols)
		exit_griderror(grid, map_lst, EINVAL);
	grid_row = malloc(sizeof(t_point) * col_count);
	if (!grid_row)
		exit_griderror(grid, map_lst, ENOMEM);
	col = -1;
	line_cpy = (char *)line;
	while (++col < grid->cols)
	{
		grid_row[col].z = ft_atoi_multi(&line_cpy);
		grid_row[col].x = col;
		grid_row[col].y = grid->rows;
		grid_row[col].color = extract_color(&line_cpy);
		transform_iso(grid_row, col);
		set_min_max(grid, &grid_row[col]); 
	}
	return (grid_row);
}

t_grid	*make_grid(t_list *map_lst)
{
	t_grid	*grid;
	t_node	*cursor;

	grid = init_grid(map_lst);
	grid->mat = malloc(sizeof(t_point *) * map_lst->len);
	if (!grid->mat)
		exit_griderror(grid, map_lst, ENOMEM);
	cursor = map_lst->head;
	while (grid->rows < (int)map_lst->len)
	{
		grid->mat[grid->rows] = make_grid_row(cursor->content, grid, map_lst);
		cursor = cursor->next;
		grid->rows++;
	}
	return (grid);
}

//just and idea if i need to change the matric frequently
//consider however that you may want to add also t_my_img *img pararmeter to function pointer, since if you change matric you'd also want to change the img
//void	grid_apply(t_grid *grid, void (*f)(t_grid *grid, int x, int y))
//{
//	int	x;
//	int	y;
//
//	x = -1;
//	while (++x < grid->cols)
//	{
//		y = -1;
//		while (++y < grid->rows)
//			f(grid, x, y);
//		x++;
//	}
//}
