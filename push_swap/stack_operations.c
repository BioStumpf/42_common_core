/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/25 15:18:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst)
{
	t_node	*tmp;

	if (lst->len < 2)
		return ;
	tmp = lst->head;
	lst->head = lst->head->next;
	tmp->next = lst->head->next;
	lst->head->next = tmp;
	if (lst->head == lst->tail)
		lst->tail = tmp;
}

void	rotate(t_list *lst)
{
	t_node	*tmp;

	if (lst->len < 2)
		return ;
	tmp = lst->head;
	lst->head = lst->head->next;
	lst->tail->next = tmp;
	lst->tail = tmp;
	tmp->next = NULL;
}

void	rrotate(t_list *lst)
{
	t_node	*sec_last;
	size_t	len;

	if (lst->len < 2)
		return ;
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
}

void	push(t_list *origin, t_list *dest)
{
	t_node	*tmp;

	if (origin->len <= 0)
		return ;
	tmp = origin->head;
	origin->head = origin->head->next;
	if (!origin->head)
		origin->tail = NULL;
	tmp->next = dest->head;
	dest->head = tmp;
	if (!dest->tail)
		dest->tail = tmp;
	origin->len--;
	dest->len++;
}
