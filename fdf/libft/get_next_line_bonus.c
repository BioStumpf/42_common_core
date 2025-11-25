/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:03:48 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/28 16:12:17 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fdlist	glob_stash[1024];
	t_fdlist		*stash;
	t_lineinfo		line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = &glob_stash[fd];
	if (!init_line(&line))
		return (NULL);
	cpy_buff_to_line(stash, &line, fd);
	line.line = ft_realloc(stash, &line, line.line_i + 1);
	return (line.line);
}
