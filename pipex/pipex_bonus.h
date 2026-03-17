/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 10:15:16 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/16 16:48:47 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
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
	char	*in;
	char	*out;
	int		access_state;
	char	*limiter;
};

void	get_program_av(struct s_dat *data, char *arg);
void	get_program_path(struct s_dat *data, char *program);
void	split_path(struct s_dat *data, char **envp);
void	cleanup(struct s_dat *data, int status, char *msg);
void	close_pipend(int *end);
void	open_fd(struct s_dat *data, int *fd, char *file, int flag);
void	create_heredoc(struct s_dat *data);
bool	check_if_path(struct s_dat *data, char *program);
void	exec_mid_child(struct s_dat *data, char **envp, char *program);
void	exec_first_child(struct s_dat *data, char **envp, char *program);
void	exec_mid_child(struct s_dat *data, char **envp, char *program);
void	exec_last_child(struct s_dat *data, char **envp, char *program);
void	remove_heredoc(struct s_dat *data);

#endif
