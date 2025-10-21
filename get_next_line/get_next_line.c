/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:47:51 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/20 19:34:32 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strjoin_and_free(char *s1, char *s2, size_t s1_len, size_t s2_len)
{
	size_t	tot_len;
	char	*out;

	tot_len = s1_len + s2_len;
	out = malloc(tot_len + 1);
	if (!out)
		return (0);
	ft_strlcpy(out, s1, tot_len + 1);
	ft_strlcpy(out + s1_len, s2, tot_len + 1);
	free(s1);
	return (out);
}

static char	*read_line(char *leftover_buff, char **current_line_start, int fd)
{
	char	*tmp_buff;
	char	*line_end;
	ssize_t	bytes_read;
	size_t	tot_bytes_read;

	line_end = NULL;
	tot_bytes_read = ft_strlen(*current_line_start);
	tmp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, tmp_buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(tmp_buff);
			return (NULL); 
		}
		tmp_buff[bytes_read] = '\0';
		*current_line_start = strjoin_and_free(*current_line_start, tmp_buff, tot_bytes_read, bytes_read);
		tot_bytes_read += bytes_read;
		line_end = ft_strchr(*current_line_start, '\n');
		if (line_end)
		{
			ft_strlcpy(leftover_buff, line_end + 1, BUFFER_SIZE);
			free(tmp_buff);
			return (line_end + 1);
		}
	}
	free(tmp_buff);
	return (*current_line_start + tot_bytes_read);
}

static char	*read_buff_and_line(char *leftover_buff, int fd)
{
	char	*line;
	char	*current_line_start;
	char	*next_line_start;

	current_line_start = ft_substr(leftover_buff, 0, BUFFER_SIZE);
	next_line_start = read_line(leftover_buff, &current_line_start, fd);
	line = ft_substr(current_line_start, 0, (next_line_start - current_line_start));
	if (!*line)
	{
		free(line);
		line = NULL;
	}
	free(current_line_start);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	leftover_buff[BUFFER_SIZE + 1];
	char		*line_end;
	char		*line;

	line_end = ft_strchr(leftover_buff, '\n');
	if (line_end)
	{
		line = ft_substr(leftover_buff, 0, (line_end - leftover_buff + 1));
		ft_strlcpy(leftover_buff, line_end + 1, BUFFER_SIZE + 1);
	}
	else
		line = read_buff_and_line(leftover_buff, fd);	
	return (line);
}
