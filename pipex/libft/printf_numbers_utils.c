/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:21:46 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/05 15:11:59 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr_rec(t_ulong num, const char *base, t_uint base_len)
{
	int	digits;

	if (base_len > num)
		return (write(1, &base[num], 1));
	digits = putnbr_rec(num / base_len, base, base_len);
	if (digits == -1)
		return (-1);
	if (write(1, &base[num % base_len], 1) == -1)
		return (-1);
	return (digits + 1);
}

int	ft_putnbr_base(t_ulong num, t_uint base_len, char base_id)
{
	const char	*base;

	if (base_id == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (putnbr_rec(num, base, base_len));
}

int	ft_putnbr_signed(int num)
{
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_putnbr_base((t_ulong)(-(long)num), 10, 'i') + 1);
	}
	else
		return (ft_putnbr_base((t_ulong)num, 10, 'i'));
}

int	print_pointer(t_ulong num)
{
	if (!num)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (ft_putnbr_base(num, 16, 'x') + 2);
}
