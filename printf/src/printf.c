/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:23:29 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/02 23:07:25 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	add_printed(int printed_bytes, int *tot_bytes)
{
	if (printed_bytes == -1)
	{
		*tot_bytes = -1;
		return (false);
	}
	*tot_bytes += printed_bytes;
	return (true);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	const char	*cursor;
	int			tot_bytes;
	int			printed_bytes;

	va_start(args, str);
	tot_bytes = 0;
	while (*str)
	{
		cursor = find_option(str);
		printed_bytes = write(1, str, cursor - str);
		if (!add_printed(printed_bytes, &tot_bytes) || !*cursor)
			break ;
		printed_bytes = print_arg(args, cursor + 1);
		if (!add_printed(printed_bytes, &tot_bytes))
			break ;
		str = cursor + 2;
	}
	va_end(args);
	return (tot_bytes);
}
