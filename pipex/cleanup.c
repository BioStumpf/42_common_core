/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 11:33:51 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/17 12:28:35 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include "libft.h"

void	close_pipend(int *end)
{
	if (*end != -1)
		close(*end);
	*end = -1;
}

static void	p_error(char *error, char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

void	cleanup(struct s_dat *data, int status, char *msg)
{
	if (msg && status == 127)
		p_error("command not found", msg);
	else if (status != 0 && msg)
		perror(msg);
	close_pipend(&data->pipe[0]);
	close_pipend(&data->pipe[1]);
	if (data->path_split)
		free_split(data->path_split);
	if (data->program_path)
		free(data->program_path);
	if (data->program_av)
		free_split(data->program_av);
	exit (status);
}
