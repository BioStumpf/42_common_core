/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:04:19 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/09 12:17:20 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static void	find_start_end(char **start, char **end, const char *set)
{
	while (**start && in_set(**start, set))
		(*start)++;
	while ((*end > *start) && in_set(*(*end - 1), set))
		(*end)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*out;
	size_t	out_len;

	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	find_start_end(&start, &end, set);
	out_len = end - start + 1;
	out = malloc(out_len);
	if (!out)
		return (0);
	ft_strlcpy(out, start, out_len);
	return (out);
}
