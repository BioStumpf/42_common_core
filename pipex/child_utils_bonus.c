/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:18:17 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/16 16:58:33 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static bool	create_enter_child(struct s_dat *data)
{
	data->pid = fork();
	if (data->pid == -1)
		cleanup(data, 1, "fork");
	return (data->pid == 0);
}

static void	exec_program(struct s_dat *data, char **envp, char *program)
{
	get_program_av(data, program);
	if (!check_if_path(data, data->program_av[0]))
		get_program_path(data, data->program_av[0]);
	execve(data->program_path, data->program_av, envp);
	cleanup(data, 1, "execve");
}

void	exec_first_child(struct s_dat *data, char **envp, char *program)
{
	if (pipe(data->pipe) == -1)
		cleanup(data, 1, "pipe");
	if (!create_enter_child(data))
		return ;
	close_pipend(&data->pipe[0]);
	open_fd(data, &data->pipe[0], data->in, IN);
	remove_heredoc(data);
	if (dup2(data->pipe[0], STDIN) == -1)
		cleanup(data, 1, "dup2");
	close_pipend(&data->pipe[0]);
	if (dup2(data->pipe[1], STDOUT) == -1)
		cleanup(data, 1, "dup2");
	close_pipend(&data->pipe[1]);
	exec_program(data, envp, program);
}

void	exec_last_child(struct s_dat *data, char **envp, char *program)
{
	if (!create_enter_child(data))
		return ;
	open_fd(data, &data->pipe[1], data->out, OUT);
	if (dup2(data->pipe[1], STDOUT) == -1)
		cleanup(data, 1, "dup2");
	close_pipend(&data->pipe[1]);
	exec_program(data, envp, program);
}

void	exec_mid_child(struct s_dat *data, char **envp, char *program)
{
	if (pipe(data->pipe) == -1)
		cleanup(data, 1, "pipe");
	if (!create_enter_child(data))
		return ;
	close_pipend(&data->pipe[0]);
	if (dup2(data->pipe[1], STDOUT) == -1)
		cleanup(data, 1, "dup2");
	close_pipend(&data->pipe[1]);
	get_program_av(data, program);
	if (!check_if_path(data, data->program_av[0]))
		get_program_path(data, data->program_av[0]);
	execve(data->program_path, data->program_av, envp);
	cleanup(data, 1, "execve");
}
