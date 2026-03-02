/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:17:57 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/28 11:25:00 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	res;
	unsigned int	digit;

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
		if (sign == 1 && res > ((unsigned int)INT_MAX - digit) / 10)
			return (INT_MAX);
		if (sign == -1 && res > ((unsigned int)INT_MIN - digit) / 10)
			return (INT_MIN);
		res = res * 10 + digit;
		nptr++;
	}
	return ((int)res * sign);
}
