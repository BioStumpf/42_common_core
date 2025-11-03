#include <stdio.h>
//#include <unistd.h>
#include "ft_printf.h"
int main(void)
{
	int ft;
	int rf;

	printf("------------------------------\n");
	printf("multiple %% should be skipped\n");
	printf("------------------------------\n");
	ft = ft_printf("ft: hello % bla % gli");
	printf("\n");
	rf = printf("rf: hello % bla % gli");
	printf("\n");
	printf("ft_ret: %d", ft); 
	printf("\n");
	printf("rf_ret: %d", rf); 
	printf("\n");
	printf("------------------------------\n");
	printf("multiple %% and %% in the end\n");
	printf("------------------------------\n");
	ft = ft_printf("ft: hello % bla % gli%");
	printf("\n");
	rf = printf("rf: hello % bla % gli%");
	printf("\n");
	printf("ft_ret: %d", ft); 
	printf("\n");
	printf("rf_ret: %d", rf); 
	printf("\n");
	printf("------------------------------\n");
	printf("invalid arg\n");
	printf("------------------------------\n");
	ft = ft_printf("ft: hello %y bla gli");
	printf("\n");
	rf = printf("rf: hello %y bla gli");
	printf("\n");
	printf("ft_ret: %d", ft); 
	printf("\n");
	printf("rf_ret: %d", rf); 
	printf("\n");
	//printf("some initial tests\n");
	//ft = ft_printf("%c, hi %s, %d\n", 'A', "David", -2147483647);
	//ref = printf("%c, hi %s, %d\n", 'A', "David", -2147483647);
	//printf("ft: %d\n", ft);
	//printf("ref: %d\n", ref);
	//printf("Now test percent only\n");
	//ft_printf("ft: %%\n");
	//printf("ref: %%\n");
	//printf("Now test unsigned %%u\n");
	//ft_printf("ft: %u\n", 1000000);
	//printf("ref: %u\n", 1000000);
	//printf("Now test hex %%x\n");
	//ft_printf("ft: %x\n", 1000000);
	//printf("ref: %x\n", 1000000);
	//printf("Now test pointer %%p\n");
	//int arr[] = {1, 2, 3};
	//ft_printf("ft: %p\n", arr);
	//printf("ref: %p\n", arr);
	//printf("Now test if it can print %% and stuff correctly after it like pointer %%p\n");
	//ft_printf("Now test if it can print %% and stuff correctly after it like pointer %%p\n");
	//printf("test NULL for %%s\n");
	//ft = ft_printf("ftt: %s, %s\n", 0, "Hello");
	//ref = printf("ref: %s, %s\n", 0, "Hello");
	//printf("ft: %d\n", ft);
	//printf("ref: %d\n", ref);
	//printf("test NULL for %%p\n");
	//ft = ft_printf("ftt: %p, %s\n", 0, "Hello");
	//ref = printf("ref: %p, %s\n", 0, "Hello");
	//printf("ft: %d\n", ft);
	//printf("ref: %d\n", ref);
	//printf("hello %");
	//printf("\n");
	//ft_printf("hello %");
}
