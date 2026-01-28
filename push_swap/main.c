/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:25:50 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/28 15:58:48 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

//static void print_fn(void *content)
//{
//	ft_printf("%d\n", *(int *)content);
//}

static int	find_indx(t_node *head, int val)
{
	size_t	indx;

	indx = 0;
	while (head)
	{
		if (val > *(int *)head->content)
			indx++;
		head = head->next;
	}
	return (indx);
}

static void	normalize_numbers(t_list *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	while (tmp)
	{
		tmp->indx = find_indx(lst->head, *(int *)tmp->content);
		tmp = tmp->next;
	}
}

//static void print_indx(t_list *lst)
//{
//	t_node	*node;
//
//	node = lst->head;
//	while (node)
//	{
//		ft_printf("%d\n", node->indx);
//		node = node->next;
//	}
//}

int main(int ac, char **av)
{
	t_list	sa;
	t_list	sb;

	if (ac < 2)
		error();
	ft_lstinit(&sa);
	ft_lstinit(&sb);
	if (!parse_inpt(ac, av, &sa))
		error();
	//swap(&sa, 'a');
	normalize_numbers(&sa);
	//ft_lstprint(&sa, print_fn); 
	//ft_printf("\n\n");
	//print_indx(&sa);
	//ft_printf("\n\n");
	//ft_lstprint(&sb, print_fn); 
	ft_lstclear(&sa, free);
	ft_lstclear(&sb, free);
	return (0);
}
