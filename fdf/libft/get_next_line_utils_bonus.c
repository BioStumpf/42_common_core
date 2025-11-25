/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:08:16 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/28 16:10:56 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

bool	init_line(t_lineinfo *line)
{
	line->line_s = BUFFER_SIZE;
	line->line_i = 0;
	line->line = malloc(BUFFER_SIZE * sizeof(char));
	if (!line->line)
		return (false);
	return (true);
}

char	*ft_realloc(t_fdlist *stash, t_lineinfo *line, size_t new_len)
{
	char	*new_line;
	size_t	i;

	new_line = malloc(new_len);
	if (!new_line || !line->line
		|| !line->line_i || stash->buff_s < 0)
	{
		free(line->line);
		free(new_line);
		return (NULL);
	}
	i = 0;
	while (i < line->line_i)
	{
		new_line[i] = (line->line)[i];
		++i;
	}
	new_line[i] = '\0';
	line->line_s = new_len;
	free(line->line);
	return (new_line);
}

void	cpy_buff_to_line(t_fdlist *stash, t_lineinfo *line, int fd)
{
	while (line->line)
	{
		if (stash->buff_i >= stash->buff_s)
		{
			stash->buff_i = 0;
			stash->buff_s = read(fd, stash->buff, BUFFER_SIZE);
		}
		if (stash->buff_s <= 0)
			break ;
		if (line->line_i >= line->line_s)
			line->line = ft_realloc(stash, line, line->line_s * 2);
		if (!line->line)
			break ;
		if (stash->buff_i < stash->buff_s && line->line)
			(line->line)[(line->line_i)++] = (stash->buff)[stash->buff_i];
		if ((stash->buff)[(stash->buff_i)++] == '\n')
			break ;
	}
}
