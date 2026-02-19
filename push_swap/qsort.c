/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:25:57 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/19 18:49:32 by dstumpf          ###   ########.fr       */
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

static size_t	find_next_push(t_list *stack, size_t min, size_t max, char s_id)
{
	t_node	*tmp;
	size_t	cur_indx;
	size_t	best_indx;
	size_t	mid;

	tmp = stack->head;
	cur_indx = 0;
	best_indx = stack->len;
	mid = (max + min) / 2;
	while (tmp)
	{
		if (s_id == 'a' && tmp->indx <= mid && tmp->indx >= min 
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

static void	optimal_rrotation(t_list *stack, size_t idx, char id)
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

static void	split_sa(t_data *dat, size_t min, size_t max)
{
	size_t	next_push_indx;

	while (true)
	{
		next_push_indx = find_next_push(dat->sa, min, max, 'a');
		if (next_push_indx == dat->sa->len)
			return ;
		optimal_rrotation(dat->sa, next_push_indx, 'a');
		push(dat->sa, dat->sb, 'b');
	}
}

static void	split_sb(t_data *dat, size_t min, size_t max)
{
	size_t	next_push_indx;

	while (true)
	{
		next_push_indx = find_next_push(dat->sb, min, max, 'b');
		if (next_push_indx == dat->sb->len)
			return ;
		optimal_rrotation(dat->sb, next_push_indx, 'b');
		push(dat->sb, dat->sa, 'a');
	}
}

void	qsort_a(t_data *dat, size_t min, size_t max)
{
	size_t	range;

	range = max - min + 1;
	if (range <= 3)
	{
		sort_three_or_lower(dat->sa, min, max);
		return ;
	}
	split_sa(dat, min, max); 
	qsort_a(dat, (max + min) / 2 + 1, max);
	qsort_b(dat, min, (max + min) / 2);
}

void	qsort_b(t_data *dat, size_t min, size_t max)
{
	size_t	i;
	size_t	range;
	size_t	bottom_targets;

	range = max - min + 1;
	if (range <= 3)
	{
		bottom_targets = targets_at_bottom(dat->sb, min, max);
		while (bottom_targets--)
			rrotate(dat->sb, 'b');
		i = range;
		while (i-- > 0)
			push(dat->sb, dat->sa, 'a');
		sort_three_or_lower(dat->sa, min, max);
		return ;
	}
	split_sb(dat, min, max); 
	qsort_a(dat, (max + min) / 2, max);
	qsort_b(dat, min, (max + min) / 2 - 1);
}
