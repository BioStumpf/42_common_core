/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:03:48 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/27 12:18:55 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*init(t_fdlist *stash)
{
	char	*line;

	if (!stash)
		return (NULL);
	stash->line_s = BUFFER_SIZE;
	stash->line_i = 0;
	line = malloc(BUFFER_SIZE * sizeof(char));
	if (!line)
		return (NULL);
	return (line);
}

static void	free_all(t_fdlist **glob_stash, char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;	
	}
	if (*glob_stash)
	{
		free_glob_stash(*glob_stash);
		*glob_stash = NULL;
	}
}

static char	*ft_realloc(t_fdlist *stash, char *line, size_t new_len)
{
	char	*new_line;
	size_t	i;

	new_line = malloc(new_len);
	if (!new_line || !line || !stash->line_i || stash->buff_s < 0)
	{
		free(line);
		free(new_line);
		return (NULL);
	}
	i = 0;
	while (i < stash->line_i)
	{
		new_line[i] = line[i];
		++i;
	}
	new_line[i] = '\0';
	stash->line_s = new_len;
	free(line);
	return (new_line);
}

static void	cpy_buff_to_line(t_fdlist *stash, char **line, int fd)
{
	while (*line)
	{
		if (stash->buff_i >= stash->buff_s)
		{
			stash->buff_i = 0;
			stash->buff_s = read(fd, stash->buff, BUFFER_SIZE);
		}
		if (stash->buff_s <= 0)
			break ;
		if (stash->line_i >= stash->line_s)
			*line = ft_realloc(stash, *line, stash->line_s * 2);
		if (!line)
			break ;
		if (stash->buff_i < stash->buff_s && *line)
			(*line)[(stash->line_i)++] = (stash->buff)[stash->buff_i];
		if ((stash->buff)[(stash->buff_i)++] == '\n')
			break ;
	}
}

char	*get_next_line(int fd)
{
	static t_fdlist	*glob_stash;
	t_fdlist		*stash;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = get_fd_stash(&glob_stash, fd);
	line = init(stash);
	if (!stash || !line)
	{
		free_all(&glob_stash, &line);
		return (NULL);
	}
	cpy_buff_to_line(stash, &line, fd);
	line = ft_realloc(stash, line, stash->line_i + 1);
	if (!line)
	{
		free_all(&glob_stash, &line);
		return (NULL);
	}
	return (line);
}
