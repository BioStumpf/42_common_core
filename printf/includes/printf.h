#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

# define uint unsigned int
# define ulong unsigned long

const char	*find_option(const char *str);
int			print_arg(va_list args, const char *arg);
int			ft_putchar(const char c);
int			ft_putstr(const char *str);
int			ft_putnbr_base(ulong num, uint base_len, bool to_up);
int			ft_putnbr_signed(int num);
int			print_pointer(ulong num);
int			ft_printf(const char *str, ...);

#endif
