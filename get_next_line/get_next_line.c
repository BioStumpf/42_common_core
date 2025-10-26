/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:03:48 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/26 11:13:46 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_fdlist	stash;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	init_stash(&stash);
	cpy_buff_to_line(&stash, fd);
	stash.line = ft_realloc(&stash, stash.line_i + 1);
	return (stash.line);
}
