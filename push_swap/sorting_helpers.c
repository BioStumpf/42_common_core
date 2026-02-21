/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:10:55 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/05 11:41:50 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	moves_to_top(size_t idx, size_t stack_len)
{
	size_t	mid;

	mid = stack_len / 2;
	if (idx == stack_len)
		return (stack_len);
	if (idx > mid)
		return (stack_len - idx);
	return (idx);
}

size_t	find_next_push(t_list *stack, size_t min, size_t max, char s_id)
{
	t_node	*tmp;
	size_t	cur_indx;
	size_t	best_indx;
	size_t	mid;

	tmp = stack->head;
	cur_indx = 0;
	best_indx = stack->len;
	mid = (max + min + 1) / 2;
	while (tmp)
	{
		if (s_id == 'a' && tmp->indx < mid && tmp->indx >= min 
		&& moves_to_top(cur_indx, stack->len) < moves_to_top(best_indx, stack->len))
			best_indx = cur_indx;
		else if (s_id == 'b' && tmp->indx >= mid && tmp->indx <= max
		&& moves_to_top(cur_indx, stack->len) < moves_to_top(best_indx, stack->len))
			best_indx = cur_indx;
		tmp = tmp->next;
		cur_indx++;
	}
	return (best_indx);
}

void	optimal_rrotation(t_list *stack, size_t idx, char id)
{
	size_t	i;
	size_t	mid;

	i = 0;
	mid = stack->len / 2;
	if (idx > mid)
	{
		idx = stack->len - idx;
		while (i++ < idx)
			rrotate(stack, id);
	}
	else
	{
		while (i++ < idx)
			rotate(stack, id);
	}
}
