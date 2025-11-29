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
	int		word;

	word_count = 0;
	word = 0;
	while (*s)
	{
		if (!word && *s != c)
		{
			word = 1;
			word_count++;
		}
		else if (word && *s == c)
			word = 0;
		s++;
	}
	return (word_count);
}
