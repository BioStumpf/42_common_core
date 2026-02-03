/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lower5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:43:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/03 12:35:45 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list *sa)
{
	size_t	first;
	size_t	sec;
	size_t	last;

	first = sa->head->indx;
	sec = sa->head->next->indx;
	last = sa->tail->indx;
	if (first > sec && first > last)
		rotate(sa, 'a');
	else if (sec > first && sec > last)
		rrotate(sa, 'a');
	if (sa->head->indx > sa->head->next->indx)
		swap(sa, 'a');
}

static size_t	find_optimal_place(t_list *stack, size_t target)
{
	t_node	*tmp;
	size_t	idx;

	idx = 0;
	tmp = stack->head;
	while (tmp)
	{
		if (target > tmp->indx)
			idx++;
		tmp = tmp->next;
	}
	return (idx);
}

static void	optimal_rrotation(t_list *stack, size_t idx, char id)
{
	size_t	i;
	size_t	mid;

	i = 0;
	mid = stack->len / 2;
	if (idx > mid || (stack->len % 2 && idx == mid))
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

static void	put_in_optimal_place(t_data *dat, size_t target)
{
	size_t	idx;
	t_list	*ori;
	t_list	*dest;

	if (dat->ori == 'a')
	{
		ori = dat->sa;
		dest = dat->sb;
	}
	else
	{
		ori = dat->sb;
		dest = dat->sa;
	}
	idx = find_optimal_place(dest, target);
	optimal_rrotation(dest, idx, dat->dest);
	push(ori, dest, dat->dest);
}

static void	resort(t_list *stack, char id)
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

void	sort_five(t_data *dat)
{
	if (dat->sa->len == 2)
	{
		swap(dat->sa, 'a');
		return ;
	}
	while (dat->sa->len > 3)
		push(dat->sa, dat->sb, 'b');
	sort_three(dat->sa);
	if (dat->sb->len == 2 && dat->sb->head->indx < dat->sb->head->next->indx)
		swap(dat->sb, 'b');
	dat->ori = 'b';
	dat->dest = 'a';
	while (dat->sb->len)
		put_in_optimal_place(dat, dat->sb->head->indx);
	resort(dat->sa, 'a');
}
