/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lower6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:43:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/19 19:23:38 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	targets_at_bottom(t_list *stack, size_t min, size_t max)
{
	t_node	*tmp;
	size_t	bottom_targets;
	size_t	range;

	tmp = stack->head;
	range = max - min + 1;
	bottom_targets = range;
	while (range--)
	{
		if (tmp->indx >= min && tmp->indx <= max)
			bottom_targets--;
		tmp = tmp->next;
	}
	return (bottom_targets);
}

static void	sort_two(t_list *sa)
{
	if (sa->head->indx > sa->head->next->indx)
		swap(sa, 'a');
}

static void	sort_three_noempty(t_list *sa)
{
	bool	rot;

	rot = false;
	if (sa->head->indx > sa->head->next->indx
		&& sa->head->indx > sa->head->next->next->indx)
	{
		swap(sa, 'a');
		rotate(sa, 'a');
		rot = true;
	}
	else if (sa->head->next->indx > sa->head->indx
		&& sa->head->next->indx > sa->head->next->next->indx)
	{
		rotate(sa, 'a');
		rot = true;
	}
	if (sa->head->indx > sa->head->next->indx)
		swap(sa, 'a');
	if (rot)
		rrotate(sa, 'a');
	if (sa->head->indx > sa->head->next->indx)
		swap(sa, 'a');
}

static void	sort_three_empty(t_list *sa)
{
	size_t	first;
	size_t	sec;
	size_t	last;

	if (sa->len == 2)
	{
		sort_two(sa);
		return ;
	}
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

void	sort_three_or_lower(t_list *sa, size_t min, size_t max)
{
	size_t	range;
	size_t	bottom_targets;

	range = max - min + 1;
	bottom_targets = targets_at_bottom(sa, min, max);
	while (bottom_targets--)
		rrotate(sa, 'a');
	if (range == 2)
	{
		sort_two(sa);
	}
	else if (sa->len == 3)
		sort_three_empty(sa);
	else 
		sort_three_noempty(sa);
}
