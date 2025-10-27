/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:51:16 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/27 10:28:51 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_fdlist
{
	char			buff[BUFFER_SIZE];
	ssize_t			buff_i;
	ssize_t			buff_s;
	size_t			line_i;
	size_t			line_s;
	int				fd;
	struct s_fdlist	*next;
}					t_fdlist;

void		free_glob_stash(t_fdlist *glob_stash);
t_fdlist	*new_stash(int fd);
t_fdlist	*add_stash(t_fdlist **glob_stash, int fd);
t_fdlist	*find_stash(t_fdlist *stash, int fd);
t_fdlist	*get_fd_stash(t_fdlist **glob_stash, int fd);
char		*get_next_line(int fd);

#endif
