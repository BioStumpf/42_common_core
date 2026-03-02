/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:00:47 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/12 19:55:18 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	in_charset(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (true);
		++charset;
	}
	return (false);
}

size_t	count_words(const char *s, const char *sep)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		while (in_charset(*s, sep))
			s++;
		if (*s)
			word_count++;
		while (*s && !in_charset(*s, sep))
			s++;
	}
	return (word_count);
}

size_t	count_nums(const char *s)
{
	size_t	num_count;

	num_count = 0;
	while (*s)
	{
		while (*s && !ft_isdigit(*s))
			s++;
		if (*s)
			num_count++;
		while (*s && ft_isdigit(*s))
			s++;
	}
	return (num_count);
}
