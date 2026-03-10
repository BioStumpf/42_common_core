/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 09:46:30 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/11 15:36:26 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include "get_next_line.h"

static void	check_args(struct s_dat *data, int ac, char **av)
{
	if (ac >= 5 && ft_strncmp("here_doc", av[1], 8) == 0)
		data->limiter = av[2];
	if (ac < 5 || (data->limiter && ac < 6))
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
	data->limiter = NULL;
}

static void	open_fd(struct s_dat *data, int *fd, char *file, int flag)
{
	if (flag == OUT && !data->limiter)
		*fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flag == OUT && data->limiter)
		*fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (flag == IN && data->limiter)
		*fd = 0;
	else
		*fd = open(file, O_RDONLY);
	if (*fd == -1)
		cleanup(data, 1, "open");
}

#include "ft_printf.h"
static void	setup_child(struct s_dat *data)
{
	if (dup2(data->pipe[0], STDIN) == -1)
	{
		ft_printf("%d\n", data->pipe[0]);
		cleanup(data, 1, "dup2 in setup");
	}
	close_pipe(data);
	if (data->out)
		open_fd(data, &data->pipe[1], data->out, OUT);
	else if (pipe(data->pipe) == -1)
		cleanup(data, 1, "pipe");
	data->pid = fork();
	if (data->pid == -1)
		cleanup(data, 1, "fork");
}

static void	exec_child(struct s_dat *data, char **envp)
{
	if (data->pid != 0)
		return ;
	if (dup2(data->pipe[1], STDOUT) == -1)
		cleanup(data, 1, "dup2");
	close_pipe(data);
	execve(data->program_path, data->program_av, envp);
	cleanup(data, 1, "execve");
}

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

static void	exec_heredoc(struct s_dat *data)
{
	int		bytes_read;
	char	*line;

	if (!data->limiter)
		return ;
	setup_child(data);
	if (data->pid != 0)
		return ;
	bytes_read = ft_strlen(line);
	while (true)
	{
		write(STDOUT, "> ", 2);
		line = get_next_line(STDIN);
		if (!line)
			cleanup(data, 0, NULL);
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

int	main(int ac, char **av, char **envp)
{
	struct s_dat	data;
	int				i;

	init_dat(&data);
	check_args(&data, ac, av);
	split_path(&data, envp);
	open_fd(&data, &data.pipe[0], av[1], IN);
	exec_heredoc(&data);
	i = 1 + (data.limiter != NULL);
	while (++i <= ac - 2)
	{
		get_program_av(&data, av[i]);
		get_program_path(&data, data.program_av[0]);
		if (i == ac - 2)
			data.out = av[ac - 1];
		setup_child(&data);
		exec_child(&data, envp);
		clean_program(&data);
	}
	waitpid(data.pid, &data.wstatus, 0);
	while (wait(NULL) != -1)
		;
	cleanup(&data, WEXITSTATUS(data.wstatus), NULL);
}
