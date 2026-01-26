#include "push_swap.h"
#include "ft_printf.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

//void	ft_lstprint(t_list *lst, void (*print_fn)(void *content));
void print_fn(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

int main(int ac, char **av)
{
	t_list	sa;
	//t_list	sb;

	if (ac < 2)
		error();
	ft_lstinit(&sa);
	if (!parse_inpt(ac, av, &sa))
		error();
	ft_printf("\n");
	ft_lstprint(&sa, print_fn); 
	ft_lstclear(&sa, free);
	return (0);
}
