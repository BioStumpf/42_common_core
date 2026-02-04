/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:10:55 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/04 15:34:43 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_optimal_place(t_list *stack, t_insert_plan *plan)
{
	t_node	*cur;
	t_node	*prev;
	size_t	i;
	size_t	opt_idx;

	i = 0;
	opt_idx = 0;
	cur = stack->head;
	prev = NULL;
	while (cur)
	{
		if (prev && plan->f(cur, prev, plan->target))
			opt_idx = i;
		prev = cur;
		cur = cur->next;
		++i;
	}
	return (opt_idx);
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

void	put_in_optimal_place(t_data *dat)
{
	size_t	idx;
	t_list	*ori;
	t_list	*dest;

	if (dat->plan.ori == 'a')
	{
		ori = dat->sa;
		dest = dat->sb;
	}
	else
	{
		ori = dat->sb;
		dest = dat->sa;
	}
	idx = find_optimal_place(dest, &dat->plan);
	optimal_rrotation(dest, idx, dat->plan.dest);
	push(ori, dest, dat->plan.dest);
}

void	resort(t_list *stack, char id)
{
	t_node	*tmp;
	size_t	idx;

	tmp = stack->head;
	idx = 1;
	while (tmp)
	{
		if (tmp->next && tmp->indx > tmp->next->indx)
			break ;
		idx++;
		tmp = tmp->next;
	}
	if (idx < stack->len)
		optimal_rrotation(stack, idx, id);
}
