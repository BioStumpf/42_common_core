#include "ft_printf.h"

static int	putnbr_rec(t_ulong num, const char *base, t_uint base_len)
{
	int	digits;

	if (base_len > num)
	{
		write(1, &base[num], 1);
		return (1);
	}
	digits = putnbr_rec(num / base_len, base, base_len);
	write(1, &base[num % base_len], 1);
	return (digits + 1);
}
 
int	ft_putnbr_base(t_ulong num, t_uint base_len, bool to_up)
{
	const char	*base;

	if (to_up)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (putnbr_rec(num, base, base_len));
}

int	ft_putnbr_signed(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr_base((t_ulong)(-(long)num), 10, false) + 1);
	}
	else
		return (ft_putnbr_base((t_ulong)num, 10, false));
}

int	print_pointer(t_ulong num)
{
	if (!num)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_putnbr_base(num, 16, false) + 2);
}
