/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex_multi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:51:31 by dstumpf           #+#    #+#             */
/*   Updated: 2025/12/09 18:54:00 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_hex_digit(char c, int *hex_digit)
{
	if ('A' <= c && c <= 'F')
		*hex_digit = c - 'A' + 10;
	if ('a' <= c && c <= 'f')
		*hex_digit = c - 'a' + 10;
	if ('0' <= c && c <= '9')
		*hex_digit = c - '0';
}

static int	ft_ishex(char c)
{
	return (('A' <= c && c <= 'F')
		|| ('a' <= c && c <= 'f')
		|| ('0' <= c && c <= '9'));
}

int	ft_atoi_hex_multi(char **nptr)
{
	int		res;
	int		hex_digit;

	res = 0;
	while (ft_iswhitespace(**nptr) || **nptr == '0' || **nptr == 'x')
		(*nptr)++;
	while (ft_ishex(**nptr))
	{
		set_hex_digit(**nptr, &hex_digit);
		if (res > (INT_MAX - hex_digit) / 16)
			res = INT_MAX;
		else
			res = res * 16 + hex_digit;
		(*nptr)++;
	}
	return (res);
}
