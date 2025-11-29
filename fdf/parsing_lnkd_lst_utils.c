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
