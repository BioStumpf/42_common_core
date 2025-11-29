/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:37:37 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/29 16:12:28 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*read_map_lst(int fd)
{
	t_list	*map_lst;
	t_node	*node;
	char	*line;

	map_lst = ft_lstnew();
	if (!map_lst)
		exit_lsterror(map_lst);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		node = ft_nodenew(line);
		if (!node)
			exit_lsterror(map_lst);
		ft_lstadd_back(map_lst, node);
	}
	return (map_lst);
}

static t_grid	*init_grid(t_list *map_lst)
{
	t_grid	*grid;

	grid = malloc(sizeof(t_grid));
	if (!grid)
	{
		errno = ENOMEM;
		return (NULL);
	}
	grid->rows = 0;
	grid->cols = 0;
	grid->mat = NULL;
}

static t_point	*split_to_int(const char *line, t_grid *grid)
{
	t_point	*row_int;
	size_t	wc;
	size_t	i;

	wc = count_words(line, ' ');
	if (grid->cols == 0)
		grid->cols = wc;
	if (wc == 0 || wc != grid->cols)
	{
		errno = EINVAL;
		return (NULL);
	}
	row_int = malloc(sizeof(t_point) * wc);
	if (!row_int)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < wc)
	{
		row_int[i].z = ft_atoi_arr(&line);	
		//call isometric conversion funcion to compute x_iso and y_iso and set grid->mat[i][j] valuesdd
		//row_int[i].iso_x = 
		//row_int[i++].iso_y = 
	return (row_int);
}

static t_grid	*make_grid(t_list *map_lst)
{
	t_grid	*grid;
	t_node	*cursor;
	int		i;

	grid = init_grid(map_lst);
	if (!grid)
		exit_griderror(grid, map_lst);
	grid->mat = malloc(sizeof(t_point *) * map_lst->len);
	if (!grid->mat)
		exit_griderror(grid, map_lst);
	cursor = map_list->head;
	i = 0;
	while (i < map_list->len)
	{
		grid->mat[i] = split_to_int(cursor, grid);
		if (!grid->mat[i])
			exit_gridfree(grid, map_lst);
		cursor++;
		i++;
	}
}

t_grid	*parse_map(int fd)
{
	t_list	*map_lst;
	t_grid	*grid;

	map_lst = read_map_lst(fd);
	grid = make_grid(map_list);
	ft_lstclear(map, free);
	return (grid);
}
