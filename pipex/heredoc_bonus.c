/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:52:32 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/16 17:24:51 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include "get_next_line.h"
#include <errno.h>

static int	find_limiter(char *line, int size, char *limiter)
{
	int	limiter_len;
	int	i;

	i = -1;
	limiter_len = (int)ft_strlen(limiter);
	if (size < limiter_len)
		return (-1);
	size -= limiter_len;
	while (++i <= size)
	{
		if (ft_strncmp(line, limiter, limiter_len) == 0)
			return (0);
	}
	return (-1);
}

void	create_heredoc(struct s_dat *data)
{
	int		bytes_read;
	char	*line;

	if (!data->limiter)
		return ;
	data->pipe[0] = open("here_doc", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (data->pipe[0] == -1)
		cleanup(data, 1, "here_doc");
	while (true)
	{
		write(STDOUT, "> ", 2);
		errno = 0;
		line = get_next_line(STDIN);
		if (errno != 0)
			cleanup(data, 1, "gnl");
		bytes_read = ft_strlen(line);
		if (find_limiter(line, bytes_read, data->limiter) == 0)
		{
			free(line);
			close_pipend(&data->pipe[0]);
			return ;
		}
		write(data->pipe[0], line, bytes_read);
		free(line);
	}
	close_pipend(&data->pipe[0]);
}

void	remove_heredoc(struct s_dat *data)
{
	if (data->limiter && unlink("here_doc") == -1)
		cleanup(data, 1, "here_doc");
}
