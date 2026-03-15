/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 11:33:51 by dstumpf             #+#    #+#             */
/*   Updated: 26/03/15 15:06:30 by dstumpf            ###   ########.fr       */
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

void	cleanup(struct s_dat *data, int status, char *msg)
{
	if (status == 1)
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

void	clean_program(struct s_dat *data)
{
	free(data->program_path);
	data->program_path = NULL;
	free_split(data->program_av);
	data->program_av = NULL;
}
