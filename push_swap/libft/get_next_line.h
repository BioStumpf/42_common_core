/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:51:16 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/26 15:20:57 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_fdlist
{
	char	buff[BUFFER_SIZE];
	ssize_t	buff_i;
	ssize_t	buff_s;
}			t_fdlist;

typedef struct s_lineinfo
{
	char	*line;
	size_t	line_i;
	size_t	line_s;
}			t_lineinfo;

char	*get_next_line(int fd);
void	cpy_buff_to_line(t_fdlist *stash, t_lineinfo *line, int fd);
char	*ft_realloc(t_fdlist *stash, t_lineinfo *line, size_t new_len);
bool	init_line(t_lineinfo *line);

#endif
