/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lnkd_lst_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:37:37 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/02 09:41:05 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_line_lst(char *line, t_list *map_lst)
{
	t_node	*node;

	node = ft_nodenew(line);
	if (!node)
	{
		free(line);
		exit_lsterror(map_lst, ENOMEM);
	}
	ft_lstadd_back(map_lst, node);
}

t_list	*read_map_lst(int fd)
{
	t_list	*map_lst;
	char	*line;

	map_lst = ft_lstnew();
	if (!map_lst)
		exit_lsterror(map_lst, ENOMEM);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		add_line_lst(line, map_lst);
	}
	if ((int)map_lst->len <= 0)
		exit_lsterror(map_lst, EINVAL);
	return (map_lst);
}
