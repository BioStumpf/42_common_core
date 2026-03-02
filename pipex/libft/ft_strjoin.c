/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 11:02:49 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/09 10:59:09 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	tot_len;
	char	*out;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tot_len = s1_len + s2_len;
	out = malloc(tot_len + 1);
	if (!out)
		return (0);
	ft_strlcpy(out, s1, tot_len + 1);
	ft_strlcat(out, s2, tot_len + 1);
	return (out);
}
