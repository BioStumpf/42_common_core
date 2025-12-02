/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_multi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:45:29 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/01 13:46:18 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(int c)
{
	return ((c == '+') || (c == '-'));
}

static int	get_sign_skip(char **nptr)
{
	int	sign;

	if (ft_issign(**nptr))
		sign = 44 - **nptr;
	else
		sign = 1;
	(*nptr)++;
	return (sign);
}

int	ft_atoi_multi(char **nptr)
{
	int		sign;
	long	res;
	long	digit;

	sign = 1;
	res = 0;
	while (**nptr && !ft_isdigit(**nptr))
		sign = get_sign_skip(nptr);
	while (ft_isdigit(**nptr))
	{
		digit = **nptr - '0';
		if (sign == 1 && res > ((long)INT_MAX - digit) / 10)
			res = INT_MAX;
		else if (sign == -1 && res > (-(long)INT_MIN - digit) / 10)
			res = (long)INT_MAX + 1;
		else
			res = res * 10 + digit;
		(*nptr)++;
	}
	return ((int)res * sign);
}
