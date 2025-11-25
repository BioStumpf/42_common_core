/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:37:37 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/25 19:58:21 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft_complete.h"



void	read_map(int fd, t_list **line_list)
{
	char	*line_buff;
	t_list	*line_node;

	while (true)
	{
		line_buff = get_next_line(fd);
		ft_printf("line: %s", line_buff);
		if (!line_buff)
			break ;
		//make t_list struct different, containing head, tail and current position, addback will change these attributes
		line_node = ft_lstnew(line_buff);
		if (!line_node)
			ft_exit_malloc();
		ft_lstadd_back(line_list, line_node); 
		free(line_buff);
	}
}

t_grid	**make_grid(t_list line_list)
{
}

int	**parse_map(int fd)
{
	t_list	*line_list;
	t_grid	**grid;

	line_list = NULL;
	line_list = read_map(fd, &line_list);
	if (!line_list)
		return (NULL);
	grid = make_grid(line_list);
}
