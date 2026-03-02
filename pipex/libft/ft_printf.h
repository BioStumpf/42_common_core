/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:20:41 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/05 15:31:45 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

const char	*find_option(const char *str);
int			print_arg(va_list args, const char *arg);
int			ft_putchar(const char c);
int			ft_putstr(const char *str);
int			ft_putnbr_base(t_ulong num, t_uint base_len, char base_id);
int			ft_putnbr_signed(int num);
int			print_pointer(t_ulong num);
int			ft_printf(const char *str, ...);

#endif
