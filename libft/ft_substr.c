/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:47:17 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/09 16:13:35 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		return (0);
	ft_strlcpy(out, s + start, len + 1);
	return (out);
}
