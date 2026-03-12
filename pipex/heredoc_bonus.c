/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:52:32 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/12 12:21:16 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include "get_next_line.h"

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

void	exec_heredoc(struct s_dat *data)
{
	int		bytes_read;
	char	*line;

	if (!data->limiter)
		return ;
	setup_child(data);
	if (data->pid != 0)
		return ;
	while (true)
	{
		write(STDOUT, "> ", 2);
		line = get_next_line(STDIN);
		if (!line)
			cleanup(data, 0, NULL);
		bytes_read = ft_strlen(line);
		if (find_limiter(line, bytes_read, data->limiter) == 0)
		{
			free(line);
			cleanup(data, 0, NULL);
		}
		write(data->pipe[1], line, bytes_read);
		free(line);
	}
	cleanup(data, 0, NULL);
}
