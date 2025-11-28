/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:37:37 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/28 18:29:12 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//make mybe line to node function

static t_list	*read_map_lst(int fd)
{
	t_list	*map_lst;
	t_node	*node;
	char	*line;

	map_lst = ft_lstnew();
	if (!map_lst)
		exit_error("Malloc failure during list initialization!");
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

//word count function ->libft take from split
//put wc and atoi in custom split_to_int function

static t_grid	**make_grid(t_list *map_lst)
{
	t_grid	*grid;
	t_node	*cursor;
	int		i;

	//allocate memory for grid
	//init rows and cols to 0
	//allocate memory for grid->mat base on map_lst->len
	cursor = map_list->head;
	i = 0;
	while (i < map_list->len)
	{
		//call split_to_int and set grid->mat[i] to it
			//compute word count
			//compare word count against grid->cols 
			//allocate memory for *mat based on word count
			//iterate through word count using j
			//convert "word" into int, acess grid->mat[i][j] and set its z value
		//call isometric conversion funcion to compute x_iso and y_iso and set grid->mat[i][j] values
		cursor++;
		i++;
	}
}

int	**parse_map(int fd)
{
	t_list	*map_lst;
	t_grid	**grid;

	map_lst = read_map_lst(fd);
	grid = make_grid(map_list);
	ft_lstclear(map, free);
}
