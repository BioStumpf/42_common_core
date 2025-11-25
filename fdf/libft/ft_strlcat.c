/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:47:19 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/08 18:29:25 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	tot_len;

	tot_len = ft_strlen(dst);
	if (size <= tot_len)
		return (size + ft_strlen(src));
	dst += tot_len;
	while (*src && (tot_len < size - 1))
	{
		*dst++ = *src++;
		tot_len++;
	}
	while (*src++)
		tot_len++;
	*dst = 0;
	return (tot_len);
}
