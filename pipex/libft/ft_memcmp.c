/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:01:13 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/03 10:21:20 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	i = 0;
	us1 = s1;
	us2 = s2;
	while ((i < n))
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
