/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 11:33:51 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/12 18:03:42 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include "libft.h"

void	cleanup(struct s_dat *data, int status, char *msg)
{
	if (status == 1)
		perror(msg);
	if (data->pipe[0] != -1)
		close(data->pipe[0]);
	if (data->pipe[1] != -1)
		close(data->pipe[1]);
	if (data->path_split)
		free_split(data->path_split);
	if (data->program_path)
		free(data->program_path);
	if (data->program_av)
		free_split(data->program_av);
	while (wait(NULL) != -1)
		;
	exit (status);
}

void	clean_program(struct s_dat *data)
{
	free(data->program_path);
	data->program_path = NULL;
	free_split(data->program_av);
	data->program_av = NULL;
}

void	close_pipe(struct s_dat *data)
{
	if (data->pipe[0] > 2)
		close(data->pipe[0]);
	if (data->pipe[1] > 2)
		close(data->pipe[1]);
	data->pipe[0] = -1;
	data->pipe[1] = -1;
}
