/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:35:13 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/12 15:03:35 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		comp;
	size_t	i;
	size_t	little_len;

	i = 0;
	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	while (big[i] && (little_len <= len - i))
	{
		comp = ft_strncmp(big + i, little, little_len);
		if (comp == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
