/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 09:46:30 by dstumpf             #+#    #+#             */
/*   Updated: 26/03/06 12:21:08 by dstumpf            ###   ########.fr       */
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
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->path_split = NULL;
	data->program_av = NULL;
	data->program_path = NULL;
	data->wstatus = 0;
	data->out = NULL;
}

static void	open_file(struct s_dat *data, int *fd, char *file, int flags)
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
	if (dup2(data->pipe_fd[0], STDIN) == -1)
		cleanup(data, 1, "dup2");
	close_pipe(data);
	if (data->out)
		open_file(data, &WREND, data->out, O_WRONLY | O_CREAT | O_TRUNC);
	else
	{
		if (pipe(data->pipe_fd) == -1)
			cleanup(data, 1, "pipe");
	}
	data->pid = fork(); 
	if (data->pid == -1)
		cleanup(data, 1, "fork");
	if (data->pid == 0)
	{
		if (dup2(WREND, STDOUT) == -1) 
			cleanup(data, 1, "dup2");
		close_pipe(data);
		execve(data->program_path, data->program_av, envp); 
		cleanup(data, 1, "execve");
	}
}

int main(int ac, char **av, char **envp)
{
	struct s_dat	data;
	int				i;

	init_dat(&data);
	check_args(ac);
	split_path(&data, envp);
	open_file(&data, &data.pipe_fd[0], av[1], O_RDONLY);
	i = 1;
	while (++i <= ac - 2)
	{
		get_program_av(&data, av[i]);
		get_program_path(&data, data.program_av[0]);
		if (i == ac - 2)
			data.out = av[ac - 2]; 
		execute_program(&data, envp);
		//if (dup2(RDEND, STDIN) == -1)
		//	cleanup(&data, 1, "dup2");
		//close_pipe(&data);
		//if (i == ac - 2)
		//	open_file(&data, &WREND, OUTPUT, O_WRONLY | O_CREAT | O_TRUNC);
		//else
		//{
		//	if (pipe(data.pipe_fd) == -1)
		//		cleanup(&data, 1, "pipe");
		//}
		//data.pid = fork(); 
		//if (data.pid == -1)
		//	cleanup(&data, 1, "fork");
		//if (data.pid == 0)
		//{
		//	if (dup2(WREND, STDOUT) == -1) 
		//		cleanup(&data, 1, "dup2");
		//	close_pipe(&data);
		//	execve(data.program_path, data.program_av, envp); 
		//	cleanup(&data, 1, "execve");
		//}
		clean_program(&data);
	}
	waitpid(data.pid, &data.wstatus, 0);
	while (wait(NULL) != -1)
		;
	cleanup(&data, WEXITSTATUS(data.wstatus), NULL);
} 
