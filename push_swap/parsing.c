/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:20:10 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/26 16:45:13 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <errno.h>

static bool	parse_arg(char *arg, t_list *lst)
{
	t_node	*new;
	int		*num;
	int		err;

	while (*arg)
	{
		num = malloc(sizeof(int));
		if (!num)
			return (false);
		new = ft_nodenew(num);
		err = 0;
		*num = ft_atoi_multi(&arg, &err);
		if ((*num == -1 && err == ERANGE) || !new || ft_lstfind(lst, num, 5))
		{
			free(num);
			free(new);
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
