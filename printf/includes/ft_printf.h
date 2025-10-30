#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

typedef unsigned int t_uint;
typedef unsigned long t_ulong;

const char	*find_option(const char *str);
int			print_arg(va_list args, const char *arg);
int			ft_putchar(const char c);
int			ft_putstr(const char *str);
int			ft_putnbr_base(t_ulong num, t_uint base_len, bool to_up);
int			ft_putnbr_signed(int num);
int			print_pointer(t_ulong num);
int			ft_printf(const char *str, ...);

#endif
