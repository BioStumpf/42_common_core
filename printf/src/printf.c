#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	const char	*cursor;
	int			bytes_printed;

	va_start(args, str); 
	bytes_printed = 0;
	while (*str)
	{
		cursor = find_option(str);
		write(1, str, cursor - str);
		bytes_printed += cursor - str;
		if (!*cursor || !*(cursor + 1))
			break ;
		bytes_printed += print_arg(args, cursor + 1);
		str = cursor + 2;
	}
	va_end(args);
	return (bytes_printed);
}	
