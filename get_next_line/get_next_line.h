/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:51:16 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/20 16:12:26 by dstumpf          ###   ########.fr       */
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
//# include <sys/types.h>

static char		*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t nmemb, size_t size);
char			*strjoin_and_free(char *s1, char *s2, size_t s1_len, size_t s2_len)
static size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
static char		*read_line(char *leftover_buff, char **current_line_start, int fd);
static char		*read_buff_and_line(char *leftover_buff, int fd);
char			*get_next_line(int fd);

#endif
