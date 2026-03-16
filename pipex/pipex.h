/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 10:15:16 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/16 14:03:13 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdbool.h>

# define STDIN 0
# define STDOUT 1
# define IN 0
# define OUT 1

struct s_dat
{
	int		pipe[2];
	int		pid;
	int		wstatus;
	size_t	colon;
	char	**path_split;
	char	**program_av;
	char	*program_path;
	char	*out;
	char	*in;
	int		access_state;
};

void	get_program_av(struct s_dat *data, char *arg);
void	get_program_path(struct s_dat *data, char *program);
void	split_path(struct s_dat *data, char **envp);
void	cleanup(struct s_dat *data, int status, char *msg);
void	close_pipend(int *end);
void	open_fd(struct s_dat *data, int *fd, char *file, int flag);
void	setup_child(struct s_dat *data);
void	exec_first_child(struct s_dat *data, char **envp, char *program);
void	exec_last_child(struct s_dat *data, char **envp, char *program);
bool	check_if_path(struct s_dat *data, char *program);

#endif
