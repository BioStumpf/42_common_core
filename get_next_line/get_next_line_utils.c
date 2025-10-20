/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:08:16 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/20 15:03:51 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*ft_strchr(const char *s, int c)
{
	unsigned char	cn;
	unsigned char	*sn;

	cn = (unsigned char)c;
	sn = (unsigned char *)s;
	while (*sn)
	{
		if (*sn == cn)
			return ((char *)sn);
		sn++;
	}
	if (*sn == cn)
		return ((char *)sn);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;
	size_t	out_size;

	if (nmemb == 0 || size == 0)
		out_size = 0;
	else if (nmemb > (SIZE_MAX / size))
		return (0);
	else
		out_size = nmemb * size;
	out = malloc(out_size);
	if (!out)
		return (0);
	ft_bzero(out, out_size);
	return (out);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		i = ft_strlen(src);
		return (i);
	}
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		start = s_len;
		len = 0;
	}
	else if (len > s_len - start)
		len = s_len - start;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s + start, len + 1);
	return (out);
}
