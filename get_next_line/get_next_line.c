/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:47:51 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/23 19:35:21 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdlib.h>
//#include <stdio.h>

//void *test_malloc(size_t size)
//{
//    static int count = 0;
//
//    if (count == 1)
//    {
//        printf("Simulated malloc failure!\n");
//        return NULL;
//    }
//    count++;
//    return malloc(size);
//}
//#define malloc(size) test_malloc(size)

//LEGEND
//lf == line_from, indicates where to get the line from (stupid line len rule)

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

static bool	lf_buff(char *ln_buff, char *pre_buff, size_t lb_len, char **line)
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

static char	*lf_file(char *pre_buff, char **ln_buff, char *tmp_buff, int fd)
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
		{
			pre_buff[0] = '\0';
			return (NULL);
		}
		lb_len += bytes_read;
		eol_found = lf_buff(*ln_buff, pre_buff, lb_len, &line);
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
	if (lf_buff(pre_buff, pre_buff, pre_len, &line))
		return (line);
	ln_buff = ft_substr(pre_buff, 0, BUFFER_SIZE);
	tmp_buff = malloc(BUFFER_SIZE + 1);
	if (ln_buff && tmp_buff)
		line = lf_file(pre_buff, &ln_buff, tmp_buff, fd);
	free(tmp_buff);
	free(ln_buff);
	return (line);
}

static char	*strjoin_and_free(t_fdlist *stash)
{
	size_t	tot_len;
	size_t	i;
	size_t	j;
	char	*out;

	i = 0;
	j = 0;
	tot_len = stash->line_s + stash->read_i;
	out = malloc(tot_len + 1);
	if (!out)
	{
		free(stash->line);
		free(stash->read);
		return (NULL);
	}
	while (line && i < stash->line_s)
		out[i] = (stash->line)[i++];
	while (i < tot_len)
		out[i++] = (stash->read)[j++]; 
	out[i] = '\0';
	free(stash->line);
	stash->line_s = i;
	return (out);
}

static char	*ft_realloc(t_fdlist *stash, size_t new_len)
{
	char	*new_line;
	size_t	i;

	if (!stash->line)
		return (NULL);
	new_line = malloc(new_len);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i <= stash->line_i)  
		new_line[i] = (stash->line)[i++];
	(stash->line)[i] = '\0';
	stash->line_s = new_len;
	free(stash->line);
	return (new_line);
}

static t_fdlist	*init_stash(t_fdlist *stash)
{
	if (!stash)
	{
		stash = malloc(sizeof(stash));
		stash->buff_i = 0;
		stash->buff_s = 0;
	}
	stash->line = malloc(BUFFER_SIZE);
	stash->line_s = 0;
	stash->line_i = 0;
	return (stash);
}

 char	*get_next_line(int fd)
{
	static t_fdlist	*stash;

	while (stash->buff_s > 0 && stash->line)
	{
		if (stash->buff_i >= stash->buff_s)
		{
			stash->buff_i = 0;
			stash->buff_s = read(fd, stash->buff, BUFFER_SIZE);
		}
		if (stash->line_i >= stash->line_s)
			stash->line = ft_realloc(stash, stash->line_s * 2);
		if (stash->buff_i < stash->buff_s && stash->line)
			(stash->line)[(stash->line_i)++] = (stash->buff)[(stash->buff_i)++];
		if ((stash->buff)[stash->buff_i] == '\n')
			break ;
	}
		stash->line = ft_realloc(stash, stash->line_i + 2);
		if (!stash->line || stash->buff_s <= 0)
			free(stash);
		return (stash->line);
}
	//buff
	//buff_i
	//buff_s
	//line
	//line_i
	//line_s
