#include "push_swap.h"
#include <errno.h>
#include "ft_printf.h"

static bool	parse_arg(char *arg, t_list *lst)
{
	t_node	*new;
	int		*num;

	while (*arg)
	{
		num = malloc(sizeof(int)); 
		if (!num)
			return (false);
		new = ft_nodenew(num);
		*num = ft_atoi_multi(&arg);
		if ((*num == -1 && errno == ERANGE) || !new)
		{
			free(num);
			return (false);
		}
		ft_lstadd_back(lst, new);
	}
	return (true);
}

bool	parse_inpt(int ac, char **av, t_list *lst)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!parse_arg(av[i], lst))
		{	
			ft_lstclear(lst, free);
			return (false);
		}
	}
	return (true);
}
