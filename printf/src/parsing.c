#include "printf.h"

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
		return (ft_putnbr_base((ulong)va_arg(args, uint), 16, false));
	else if (*arg == 'X')
		return (ft_putnbr_base((ulong)va_arg(args, uint), 16, true));
	else if (*arg == 'p')
		return (print_pointer(va_arg(args, ulong)));
	else if (*arg == 'u')
		return (ft_putnbr_base((ulong)va_arg(args, uint), 10, false));
	else if (*arg == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
