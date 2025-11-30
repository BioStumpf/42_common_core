/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:30:38 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/29 12:38:58 by dstumpf          ###   ########.fr       */
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
	t_point	*row_int;
	char	*line_cpy;
	int		nc;
	int		i;

	nc = (int)count_nums(line);
	if (grid->cols == 0)
		grid->cols = nc;
	if (nc <= 0 || nc != grid->cols)
		exit_griderror(grid, map_lst, EINVAL);
	row_int = malloc(sizeof(t_point) * nc);
	if (!row_int)
		exit_griderror(grid, map_lst, ENOMEM);
	i = 0;
	line_cpy = (char *)line;
	while (i < nc)
	{
		row_int[i++].z = ft_atoi_multi(&line_cpy);	
		//call isometric conversion funcion to compute x_iso and y_iso and set grid->mat[i][j] valuesdd
		//row_int[i].iso_x = 
		//row_int[i++].iso_y = 
	}
	return (row_int);
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
