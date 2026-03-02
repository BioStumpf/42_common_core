/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:43:47 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/02 09:35:26 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_backward(char *dest, const char *src, size_t n)
{
	while (n)
	{
		n--;
		dest[n] = src[n];
	}
}

static void	copy_forward(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_cpy;
	char		*dest_cpy;

	dest_cpy = dest;
	src_cpy = src;
	if (dest > src)
		copy_backward(dest_cpy, src_cpy, n);
	else if (src > dest)
		copy_forward(dest_cpy, src_cpy, n);
	return (dest);
}
