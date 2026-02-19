/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/19 16:01:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	push(t_list *origin, t_list *dest, char dest_stack)
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
	ft_printf("p%c\n", dest_stack);
}
