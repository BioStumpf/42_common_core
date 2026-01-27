/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/27 19:47:19 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	swap(t_list *lst, char stack)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->head = lst->head->next;
	tmp->next = lst->head->next;
	lst->head->next = tmp;
	if (stack)
		ft_printf("s%c\n", stack);
}

void	swap_both(t_list *sa, t_list *sb)
{
	swap(sa, 0);
	swap(sb, 0);
	ft_printf("ss\n");
}

void	rotate(t_list *lst, char stack)
{
	t_node	*tmp;

	tmp = lst->head;
	lst->head = lst->head->next;
	lst->tail->next = tmp;
	lst->tail = tmp;
	tmp->next = NULL;
	if (stack)
		ft_printf("r%c\n", stack);
}

void	rrotate(t_list *lst, char stack)
{
	t_node	*sec_last;
	size_t	len;

	len = lst->len;
	sec_last = lst->head;
	while (len > 2)
	{
		sec_last = sec_last->next;
		--len;
	}
	lst->tail->next = lst->head;
	lst->head = lst->tail;
	lst->tail = sec_last;
	lst->tail->next = NULL;
	if (stack)
		ft_printf("rr%c\n", stack);
}

void	rot_or_rrot_both(t_list *a, t_list *b, int direction)
{
	if (direction == REV)
	{
		rrotate(a, 0);
		rrotate(b, 0);
		ft_printf("rrr\n");
	}
	else
	{
		rotate(a, 0);
		rotate(b, 0);
		ft_printf("rr\n");
	}
}
