/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:50:16 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/09 11:01:14 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*out;

	i = 0;
	len = ft_strlen(s);
	out = malloc(len + 1);
	if (!out)
		return (0);
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
