/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:10:55 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/25 19:13:33 by dstumpf          ###   ########.fr       */
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
	size_t	curi;
	size_t	bsti;
	size_t	mid;

	tmp = stack->head;
	curi = 0;
	bsti = stack->len;
	mid = (max + min + 1) / 2;
	while (tmp)
	{
		if (s_id == 'a' && tmp->indx < mid && tmp->indx >= min
			&& moves_to_top(curi, stack->len) < moves_to_top(bsti, stack->len))
			bsti = curi;
		else if (s_id == 'b' && tmp->indx >= mid && tmp->indx <= max
			&& moves_to_top(curi, stack->len) < moves_to_top(bsti, stack->len))
			bsti = curi;
		tmp = tmp->next;
		curi++;
	}
	return (bsti);
}

static void	rrotate_a_or_b(t_data *dat, char stack_id, int direction)
{
	if (stack_id == 'a' && direction == FOR)
		check_n_store_ops(dat->sa, dat->sb, RA);
	else if (stack_id == 'b' && direction == FOR)
		check_n_store_ops(dat->sa, dat->sb, RB);
	if (stack_id == 'a' && direction == REV)
		check_n_store_ops(dat->sa, dat->sb, RRA);
	if (stack_id == 'b' && direction == REV)
		check_n_store_ops(dat->sa, dat->sb, RRB);
}

void	optimal_rrotation(t_data *dat, size_t idx, char stack_id)
{
	size_t	i;
	size_t	stack_len;

	i = 0;
	if (stack_id == 'a')
		stack_len = dat->sa->len;
	else
		stack_len = dat->sb->len;
	if (idx > (stack_len / 2))
	{
		idx = stack_len - idx;
		while (i++ < idx)
			rrotate_a_or_b(dat, stack_id, REV);
	}
	else
	{
		while (i++ < idx)
			rrotate_a_or_b(dat, stack_id, FOR);
	}
}
