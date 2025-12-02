/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_grid_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:30:38 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/02 09:40:49 by dstumpf          ###   ########.fr       */
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
	grid->rows = 0;
	grid->cols = 0;
	grid->mat = NULL;
	return (grid);
}

static t_point	*make_grid_row(void *line, t_grid *grid, t_list *map_lst)
{
	t_point	*grid_row;
	char	*line_cpy;
	int		col_count;
	int		col;

	col_count = (int)count_nums(line);
	if (grid->cols == 0)
		grid->cols = col_count;
	if (col_count <= 0 || col_count != grid->cols)
		exit_griderror(grid, map_lst, EINVAL);
	grid_row = malloc(sizeof(t_point) * col_count);
	if (!grid_row)
		exit_griderror(grid, map_lst, ENOMEM);
	col = 0;
	line_cpy = (char *)line;
	while (col < grid->cols)
	{
		grid_row[col].z = ft_atoi_multi(&line_cpy);
		transform_iso(grid_row, col, grid->rows);
		col++;
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
