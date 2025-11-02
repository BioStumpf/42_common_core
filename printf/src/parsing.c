/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:22:45 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/02 23:01:01 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*find_option(const char *str)
{
	while (*str && *str != '%')
		str++;
	return (str);
}

int	print_arg(va_list args, const char *arg)
{
	if (*arg == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*arg == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*arg == 'd')
		return (ft_putnbr_signed(va_arg(args, int)));
	else if (*arg == 'i')
		return (ft_putnbr_signed(va_arg(args, int)));
	else if (*arg == 'x')
		return (ft_putnbr_base((t_ulong)va_arg(args, t_uint), 16, 'x'));
	else if (*arg == 'X')
		return (ft_putnbr_base((t_ulong)va_arg(args, t_uint), 16, 'X'));
	else if (*arg == 'p')
		return (print_pointer(va_arg(args, t_ulong)));
	else if (*arg == 'u')
		return (ft_putnbr_base((t_ulong)va_arg(args, t_uint), 10, 'u'));
	else if (*arg == '%')
		return (ft_putchar('%'));
	else if (*arg == '\0')
		return (-1);
	else
		return (0);
}
