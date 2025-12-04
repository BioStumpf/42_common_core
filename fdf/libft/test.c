#include "libft.h"
#include <stdio.h>
#include "ft_printf.h"

int main(int ac, char **av)
{
	if (ac !=2 )
		return (1);
	char *str = av[1];
	int res = ft_atoi_hex_multi(&str);
	ft_printf("%d\n", res);
}
