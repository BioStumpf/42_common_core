/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:30:10 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/12 15:05:44 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pathjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	tot_len;
	bool	slash[2];
	char	*out;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1_len || !s2_len)
		return (0);
	tot_len = s1_len + s2_len;
	slash[0] = s1[s1_len - 1] == '/';
	slash[1] = s2[0] == '/';
	out = malloc(tot_len + !slash[0] + !slash[1]);
	if (!out)
		return (0);
	ft_strlcpy(out, s1, s1_len + 1);
	if (!slash[0])
	{
		out[s1_len] = '/';
		out[s1_len + 1] = '\0';
	}
	ft_strlcat(out + s1_len + !slash[0], s2 + slash[1], tot_len + 2);
	return (out);
}
