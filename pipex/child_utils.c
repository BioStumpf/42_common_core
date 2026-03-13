/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:18:17 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/12 17:34:51 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_child(struct s_dat *data)
{
	if (dup2(data->pipe[0], STDIN) == -1)
		cleanup(data, 1, "dup2");
	close_pipe(data);
	if (data->out)
		open_fd(data, &data->pipe[1], data->out, OUT);
	else if (pipe(data->pipe) == -1)
		cleanup(data, 1, "pipe");
	data->pid = fork();
	if (data->pid == -1)
		cleanup(data, 1, "fork");
}

void	exec_child(struct s_dat *data, char **envp)
{
	if (data->pid != 0)
		return ;
	if (dup2(data->pipe[1], STDOUT) == -1)
		cleanup(data, 1, "dup2");
	close_pipe(data);
	execve(data->program_path, data->program_av, envp);
	cleanup(data, 1, "execve");
}
