/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:18:11 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/09 10:57:44 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
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

static void	find_word(const char *s, char c, unsigned int *start, size_t *len)
{
	*start += *len;
	*len = 0;
	while (s[*start] && s[*start] == c)
		(*start)++;
	while (s[*start + *len] && s[*start + *len] != c)
		(*len)++;
}

static void	free_out(char **out, size_t len)
{
	while (len)
		free(out[--len]);
	free(out);
}

static int	fill_array(const char *s, char c, char **out, size_t wc)
{
	size_t			i;
	size_t			len;
	unsigned int	start;

	i = 0;
	start = 0;
	len = 0;
	while (i < wc)
	{
		find_word(s, c, &start, &len);
		out[i] = ft_substr(s, start, len);
		if (!out[i])
		{
			free_out(out, i);
			return (0);
		}
		i++;
	}
	out[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**out;
	size_t			wc;

	wc = count_words(s, c);
	if (!*s || wc == 0)
		wc = 0;
	out = malloc(sizeof(char *) * (wc + 1));
	if (!out)
		return (0);
	if (!fill_array(s, c, out, wc))
		return (0);
	return (out);
}
