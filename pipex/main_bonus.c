/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 09:46:30 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/12 12:49:47 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

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
		if (!check_if_path(&data, av[i]))
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
