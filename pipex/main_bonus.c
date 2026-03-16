/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 09:46:30 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/16 15:15:43 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

static void	check_args(struct s_dat *data, int ac, char **av)
{
	if (ac >= 5 && ft_strncmp("here_doc", av[1], 8) == 0)
		data->limiter = av[2];
	else
		data->limiter = NULL;
	if (ac < 5 || (data->limiter && ac < 6))
	{
		write(2, "Invalid number of arguments\n", 29);
		exit(1);
	}
}
static void	init_dat(struct s_dat *data, char *in, char *out)
{
	data->pipe[0] = -1;
	data->pipe[1] = -1;
	data->path_split = NULL;
	data->program_av = NULL;
	data->program_path = NULL;
	data->wstatus = 0;
	data->in = in;
	data->out = out;
	data->access_state = 127;
}

void	open_fd(struct s_dat *data, int *fd, char *file, int flag)
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
		cleanup(data, 1, file);
}

static void close_and_link_pipe(struct s_dat *data)
{
	if (dup2(data->pipe[0], STDIN) == -1)
		cleanup(data, 1, "dup2: parent");
	close_pipend(&data->pipe[0]);
	close_pipend(&data->pipe[1]);
}

int	main(int ac, char **av, char **envp)
{
	struct s_dat	data;
	int				i;

	check_args(&data, ac, av);
	init_dat(&data, av[1], av[ac - 1]);
	split_path(&data, envp);
	//exec_heredoc(&data);
	exec_first_child(&data, envp, av[2 + (data.limiter != NULL)]); 
	close_and_link_pipe(&data);
	i = 2 + (data.limiter != NULL);
	while (++i < ac - 2)
	{
		exec_mid_child(&data, envp, av[i]);
		close_and_link_pipe(&data);
	}
	exec_last_child(&data, envp, av[ac - 2]); 
	close(STDIN);
	waitpid(data.pid, &data.wstatus, 0);
	while (wait(NULL) != -1)
		;
	if (WIFEXITED(data.wstatus))
		cleanup(&data, WEXITSTATUS(data.wstatus), NULL);
	else if (WIFSIGNALED(data.wstatus))
		cleanup(&data, 128 + WTERMSIG(data.wstatus), NULL);
}
