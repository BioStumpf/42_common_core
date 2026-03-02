/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:23:00 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/09 18:01:27 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
