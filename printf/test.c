#include <stdio.h>
//#include <unistd.h>
#include "printf.h"
int main(void)
{
	printf("some initial tests\n");
	int ft = ft_printf("%c, hi %s, %d\n", 'A', "David", 2147483647);
	int ref = printf("%c, hi %s, %d\n", 'A', "David", 2147483647);
	printf("ft: %d\n", ft);
	printf("ref: %d\n", ref);
	printf("Now test percent only\n");
	ft_printf("ft: %%\n");
	printf("ref: %%\n");
	printf("Now test unsigned %%u\n");
	ft_printf("ft: %u\n", 1000000);
	printf("ref: %u\n", 1000000);
	printf("Now test hex %%x\n");
	ft_printf("ft: %x\n", 1000000);
	printf("ref: %x\n", 1000000);
	printf("Now test pointer %%p\n");
	int arr[] = {1, 2, 3};
	ft_printf("ft: %p\n", arr);
	printf("ref: %p\n", arr);
	printf("Now test if it can print %% and stuff correctly after it like pointer %%p\n");
	ft_printf("Now test if it can print %% and stuff correctly after it like pointer %%p\n");
}
