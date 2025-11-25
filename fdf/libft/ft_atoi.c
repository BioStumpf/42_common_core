/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:17:57 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/09 15:57:57 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(const char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		||c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	res;
	int				digit;

	sign = 1;
	res = 0;
	while (ft_iswhitespace(*nptr))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		sign = 44 - *nptr;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (sign == 1 && res > ((unsigned long)LONG_MAX - digit) / 10)
			return (-1);
		if (sign == -1 && res > ((unsigned long)LONG_MIN - digit) / 10)
			return (0);
		res = res * 10 + digit;
		nptr++;
	}
	return ((int)res * sign);
}
