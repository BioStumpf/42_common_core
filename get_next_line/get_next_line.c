/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:47:51 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/22 17:38:07 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

//void *test_malloc(size_t size)
//{
//    static int count = 0;
//
//    if (count == 3)
//    {
//        printf("Simulated malloc failure!\n");
//        return NULL;
//    }
//    count++;
//    return malloc(size);
//}
//#define malloc(size) test_malloc(size)

static char	*strjoin_and_free(char *s1, char *s2, size_t s1_len, size_t s2_len)
{
	size_t	tot_len;
	char	*out;

	tot_len = s1_len + s2_len;
	out = malloc(tot_len + 1);
	if (!out)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(out, s1, tot_len + 1);
	ft_strlcpy(out + s1_len, s2, tot_len + 1);
	free(s1);
	return (out);
}

static ssize_t	read_join(char **ln_buff, size_t lb_len, char *tmp_buff, int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, tmp_buff, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	tmp_buff[bytes_read] = '\0';
	*ln_buff = strjoin_and_free(*ln_buff, tmp_buff, lb_len, bytes_read);
	if (!*ln_buff)
		return (-1);
	return (bytes_read);
}

static bool	get_line(char *ln_buff, char *pre_buff, size_t lb_len, char **line)
{
	char	*line_end;
	size_t	line_len;

	line_end = ft_strchr(ln_buff, '\n');
	if (line_end)
	{
		line_len = line_end - ln_buff + 1;
		*line = ft_substr(ln_buff, 0, line_len);
		ft_strlcpy(pre_buff, line_end + 1, (lb_len - line_len + 1));
		return (true);
	}
	return (false);
}

char	*extract_line(char *pre_buff, char **ln_buff, char *tmp_buff, int fd)
{
	char	*line;
	size_t	lb_len;
	ssize_t	bytes_read;
	bool	eol_found;

	lb_len = ft_strlen(*ln_buff);
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read_join(ln_buff, lb_len, tmp_buff, fd);
		if (bytes_read < 0)
			return (NULL);
		lb_len += bytes_read;
		eol_found = get_line(*ln_buff, pre_buff, lb_len, &line);
		if (eol_found)
			return (line);
	}
	pre_buff[0] = '\0';
	if (**ln_buff)
		return (ft_substr(*ln_buff, 0, lb_len));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	pre_buff[BUFFER_SIZE + 1];
	char		*ln_buff;
	char		*tmp_buff;
	char		*line;
	size_t		pre_len;

	line = NULL;
	pre_len = ft_strlen(pre_buff);
	if (get_line(pre_buff, pre_buff, pre_len, &line))
		return (line);
	ln_buff = ft_substr(pre_buff, 0, BUFFER_SIZE);
	tmp_buff = malloc(BUFFER_SIZE + 1);
	if (ln_buff && tmp_buff)
		line = extract_line(pre_buff, &ln_buff, tmp_buff, fd);
	free(tmp_buff);
	free(ln_buff);
	return (line);
}
