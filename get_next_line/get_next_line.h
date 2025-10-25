/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:51:16 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/25 16:16:32 by dstumpf          ###   ########.fr       */
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
# include <stdint.h>

typedef struct s_fdlist
{
	char	buff[BUFFER_SIZE];
	ssize_t	buff_i;
	ssize_t	buff_s;
	char	*line;
	size_t	line_i;
	size_t	line_s;
}			t_fdlist;

char	*get_next_line(int fd);

#endif
