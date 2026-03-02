/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:15:38 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/07 10:28:43 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int n)
{
	size_t	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	abs_digit(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

static void	fill_string(char *out, size_t pos, int n)
{
	out[pos--] = 0;
	if (n == 0)
		out[pos] = '0';
	if (n < 0)
		out[0] = '-';
	while (n)
	{
		out[pos] = abs_digit(n % 10) + '0';
		n /= 10;
		pos--;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*out;

	len = int_len(n);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (0);
	fill_string(out, len, n);
	return (out);
}
