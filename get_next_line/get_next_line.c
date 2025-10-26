/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:03:48 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/26 11:10:14 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_realloc(t_fdlist *stash, size_t new_len)
{
	char	*new_line;
	size_t	i;

	new_line = malloc(new_len);
	if (!new_line || !stash->line || !stash->line_i || stash->buff_s < 0)
	{
		free(new_line);
		free(stash->line);
		return (NULL);
	}
	i = 0;
	while (i < stash->line_i)
	{
		new_line[i] = (stash->line)[i];
		++i;
	}
	new_line[i] = '\0';
	stash->line_s = new_len;
	free(stash->line);
	return (new_line);
}

void	init_stash(t_fdlist *stash)
{
	stash->line_s = BUFFER_SIZE;
	stash->line_i = 0;
	stash->line = malloc(BUFFER_SIZE * sizeof(char));
}

void	cpy_buff_to_line(t_fdlist *stash, int fd)
{
	while (stash->line)
	{
		if (stash->buff_i >= stash->buff_s)
		{
			stash->buff_i = 0;
			stash->buff_s = read(fd, stash->buff, BUFFER_SIZE);
		}
		if (stash->buff_s <= 0)
			break ;
		if (stash->line_i >= stash->line_s)
			stash->line = ft_realloc(stash, stash->line_s * 2);
		if (!stash->line)
			break ;
		if (stash->buff_i < stash->buff_s && stash->line)
			(stash->line)[(stash->line_i)++] = (stash->buff)[stash->buff_i];
		if ((stash->buff)[(stash->buff_i)++] == '\n')
			break ;
	}
}

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
