/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_multi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:45:29 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/26 16:37:32 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errno.h"

static void	get_sign_skip(char **nptr, int *sign)
{
	if (**nptr == '-')
		*sign = -1;
	if (**nptr == '-' || **nptr == '+')
		(*nptr)++;
}

static long	get_int(int sign, char **nptr, int *err)
{
	long	res;
	long	digit;

	res = 0;
	while (ft_isdigit(**nptr))
	{
		digit = **nptr - '0';
		if ((sign == 1 && res > ((long)INT_MAX - digit) / 10)
			|| (sign == -1 && res > (-(long)INT_MIN - digit) / 10))
		{
			*err = ERANGE;
			return (-1);
		}
		res = res * 10 + digit;
		(*nptr)++;
	}
	return (res * sign);
}

int	ft_atoi_multi(char **nptr, int *err)
{
	int		sign;
	int		res;

	sign = 1;
	while (**nptr && ft_iswhitespace(**nptr))
		(*nptr)++;
	get_sign_skip(nptr, &sign);
	if (**nptr && !ft_isdigit(**nptr))
	{
		*err = ERANGE;
		return (-1);
	}
	res = (int)get_int(sign, nptr, err);
	while (**nptr && ft_iswhitespace(**nptr))
		(*nptr)++;
	return (res);
}
