/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 10:15:16 by dstumpf             #+#    #+#             */
/*   Updated: 26/03/06 12:17:26 by dstumpf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/wait.h>

# define RDEND data->pipe_fd[0] 
# define WREND data->pipe_fd[1]
# define STDIN 0
# define STDOUT 1
# define INPUT av[1]
# define OUTPUT av[ac - 1]

struct s_dat
{
	int		pipe_fd[2];
	int		pid;
	int		wstatus;
	char	**path_split;
	char	**program_av;
	char	*program_path;
	char	*out;
};

void	get_program_av(struct s_dat *data, char *arg);
void	get_program_path(struct s_dat *data, char *program);
void	split_path(struct s_dat *data, char **envp);
void	cleanup(struct s_dat *data, int status, char *msg);
void	clean_program(struct s_dat *data);
void	close_pipe(struct s_dat *data);

#endif
