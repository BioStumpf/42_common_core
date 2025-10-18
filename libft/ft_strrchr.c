/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:42:21 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/12 13:18:15 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	cn;
	unsigned char	*sn;
	char			*out;

	cn = (unsigned char)c;
	sn = (unsigned char *)s;
	out = 0;
	while (*sn)
	{
		if (*sn == cn)
			out = (char *)sn;
		sn++;
	}
	if (*sn == cn)
		out = (char *)sn;
	return (out);
}
