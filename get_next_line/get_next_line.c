/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:47:51 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/25 14:05:00 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_realloc(t_fdlist *stash, size_t new_len)
{
	char	*new_line;
	size_t	i;

	if (!stash->line || new_len == 1)
		return (NULL);
	new_line = malloc(new_len);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < stash->line_i)  
	{
		new_line[i] = (stash->line)[i];
		++i;
	}
	new_line[i] = '\0';
	stash->line_s = new_len;
	free(stash->line);
	stash->line = NULL;
	return (new_line);
}

static void	free_stash(t_fdlist **stash)
{
	if ((*stash)->line)
	{
		free((*stash)->line);
		(*stash)->line = NULL;
	}
	free(*stash);
	*stash = NULL;
}

static t_fdlist	*handle_stash(t_fdlist *stash)
{
	if (stash && stash->buff_s <= 0)
	{
		free_stash(&stash);
		return (NULL);
	}
	if (!stash)
	{
		stash = malloc(sizeof(t_fdlist));
		stash->buff_i = 1;
		stash->buff_s = 1;
	}
	stash->line = malloc(BUFFER_SIZE);
	stash->line_s = BUFFER_SIZE;
	stash->line_i = 0;
	return (stash);
}

char	*get_next_line(int fd)
{
	static t_fdlist	*stash;
	char			*out;

	stash = handle_stash(stash);
	if (!stash)
		return (NULL);
	while (stash->line && stash->buff_s > 0)
	{
		if (stash->buff_i >= stash->buff_s)
		{
			stash->buff_i = 0;
			stash->buff_s = read(fd, stash->buff, BUFFER_SIZE);
			stash->buff[0] = '\0';
		}
		if (stash->line_i >= stash->line_s)
			stash->line = ft_realloc(stash, stash->line_s * 2);
		if (stash->buff_i < stash->buff_s && stash->line)
			(stash->line)[(stash->line_i)++] = (stash->buff)[stash->buff_i];
		if ((stash->buff)[(stash->buff_i)++] == '\n')
			break ;
	}
		out = ft_realloc(stash, stash->line_i + 1);
		if (!out)
			free_stash(&stash);
		return (out);
}
