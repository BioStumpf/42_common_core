/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:00:47 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/29 12:01:50 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != c)
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
