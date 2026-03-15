/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 09:46:30 by dstumpf             #+#    #+#             */
/*   Updated: 26/03/15 15:05:54 by dstumpf            ###   ########.fr       */
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
}

void	open_fd(struct s_dat *data, int *fd, char *file, int flag)
{
	if (flag == OUT)
		*fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		*fd = open(file, O_RDONLY);
	if (*fd == -1)
		cleanup(data, 1, file);
}

int	main(int ac, char **av, char **envp)
{
	struct s_dat	data;

	check_args(ac);
	init_dat(&data, av[1], av[4]);
	split_path(&data, envp);
	exec_first_child(&data, envp, av[2]); 
	if (dup2(data.pipe[0], STDIN) == -1)
		cleanup(&data, 1, "dup2: parent");
	close_pipend(&data.pipe[0]);
	close_pipend(&data.pipe[1]);
	exec_last_child(&data, envp, av[3]); 
	close(STDIN);
	waitpid(data.pid, &data.wstatus, 0);
	while (wait(NULL) != -1)
		;
	cleanup(&data, WEXITSTATUS(data.wstatus), NULL);
}
