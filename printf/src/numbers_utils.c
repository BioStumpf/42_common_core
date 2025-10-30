#include "printf.h"

static int	putnbr_rec(ulong num, const char *base, uint base_len)
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
 
int	ft_putnbr_base(ulong num, uint base_len, bool to_up)
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
	long	nb;

	if (num < 0)
	{
		nb = -(long)num;
		write(1, "-", 1);
		return (ft_putnbr_base((ulong)nb, 10, false));
	}
	return (ft_putnbr_base((ulong)num, 10, false));
}

int	print_pointer(ulong num)
{
	write(1, "0x", 2);
	return (ft_putnbr_base(num, 16, false) + 2);
}
