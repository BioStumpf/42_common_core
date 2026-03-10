/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 09:46:30 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/10 12:32:03 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static void	check_args(int ac)
{
	if (ac != 5)
	{
		write(2, "Invalid number of arguments\n", 29);
		exit(1);
	}
}

static void	init_dat(struct s_dat *data)
{
	data->pipe[0] = -1;
	data->pipe[1] = -1;
	data->path_split = NULL;
	data->program_av = NULL;
	data->program_path = NULL;
	data->wstatus = 0;
	data->out = NULL;
}

static void	open_fd(struct s_dat *data, int *fd, char *file, int flags)
{
	if (flags & O_WRONLY)
		*fd = open(file, flags, 0644);
	else
		*fd = open(file, flags);
	if (*fd == -1)
		cleanup(data, 1, "open");
}

static void	execute_program(struct s_dat *data, char **envp)
{
	if (dup2(data->pipe[0], STDIN) == -1)
		cleanup(data, 1, "dup2");
	close_pipe(data);
	if (data->out)
		open_fd(data, &data->pipe[1], data->out, O_WRONLY | O_CREAT | O_TRUNC);
	else if (pipe(data->pipe) == -1)
		cleanup(data, 1, "pipe");
	data->pid = fork();
	if (data->pid == -1)
		cleanup(data, 1, "fork");
	if (data->pid == 0)
	{
		if (dup2(data->pipe[1], STDOUT) == -1)
			cleanup(data, 1, "dup2");
		close_pipe(data);
		execve(data->program_path, data->program_av, envp);
		cleanup(data, 1, "execve");
	}
}

int	main(int ac, char **av, char **envp)
{
	struct s_dat	data;
	int				i;

	init_dat(&data);
	check_args(ac);
	split_path(&data, envp);
	open_fd(&data, &data.pipe[0], av[1], O_RDONLY);
	i = 1;
	while (++i <= ac - 2)
	{
		get_program_av(&data, av[i]);
		get_program_path(&data, data.program_av[0]);
		if (i == ac - 2)
			data.out = av[ac - 1];
		execute_program(&data, envp);
		clean_program(&data);
	}
	waitpid(data.pid, &data.wstatus, 0);
	while (wait(NULL) != -1)
		;
	cleanup(&data, WEXITSTATUS(data.wstatus), NULL);
}
