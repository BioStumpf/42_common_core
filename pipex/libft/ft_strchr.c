/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:53:37 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/12 13:16:43 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cn;
	unsigned char	*sn;

	cn = (unsigned char)c;
	sn = (unsigned char *)s;
	while (*sn)
	{
		if (*sn == cn)
			return ((char *)sn);
		sn++;
	}
	if (*sn == cn)
		return ((char *)sn);
	return (0);
}
