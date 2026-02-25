/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:43:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/25 19:15:51 by dstumpf          ###   ########.fr       */
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

static void	sort_two(t_data *dat)
{
	if (dat->sa->head->indx > dat->sa->head->next->indx)
		check_n_store_ops(dat->sa, dat->sb, SA);
}

static void	sort_three_noempty(t_data *dat)
{
	bool	rot;

	rot = false;
	if (dat->sa->head->indx > dat->sa->head->next->indx
		&& dat->sa->head->indx > dat->sa->head->next->next->indx)
	{
		check_n_store_ops(dat->sa, dat->sb, SA);
		check_n_store_ops(dat->sa, dat->sb, RA);
		rot = true;
	}
	else if (dat->sa->head->next->indx > dat->sa->head->indx
		&& dat->sa->head->next->indx > dat->sa->head->next->next->indx)
	{
		check_n_store_ops(dat->sa, dat->sb, RA);
		rot = true;
	}
	if (dat->sa->head->indx > dat->sa->head->next->indx)
		check_n_store_ops(dat->sa, dat->sb, SA);
	if (rot)
		check_n_store_ops(dat->sa, dat->sb, RRA);
	if (dat->sa->head->indx > dat->sa->head->next->indx)
		check_n_store_ops(dat->sa, dat->sb, SA);
}

static void	sort_three_empty(t_data *dat)
{
	size_t	first;
	size_t	sec;
	size_t	last;

	if (dat->sa->len == 2)
	{
		sort_two(dat);
		return ;
	}
	first = dat->sa->head->indx;
	sec = dat->sa->head->next->indx;
	last = dat->sa->tail->indx;
	if (first > sec && first > last)
		check_n_store_ops(dat->sa, dat->sb, RA);
	else if (sec > first && sec > last)
		check_n_store_ops(dat->sa, dat->sb, RRA);
	if (dat->sa->head->indx > dat->sa->head->next->indx)
		check_n_store_ops(dat->sa, dat->sb, SA);
}

void	sort_three_or_lower(t_data *dat, size_t min, size_t max)
{
	size_t	range;
	size_t	bottom_targets;

	range = max - min + 1;
	bottom_targets = targets_at_bottom(dat->sa, min, max);
	while (bottom_targets--)
		check_n_store_ops(dat->sa, dat->sb, RRA);
	if (range == 2)
		sort_two(dat);
	else if (dat->sa->len == 3)
		sort_three_empty(dat);
	else
		sort_three_noempty(dat);
}
