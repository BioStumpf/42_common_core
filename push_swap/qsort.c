/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:25:57 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/26 17:50:47 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_sa(t_data *dat, size_t min, size_t max)
{
	size_t	next_push_indx;
	size_t	range;

	range = max - min + 1;
	if (dat->sa->len == range)
		dat->find_next = find_next_push_empty;
	else
		dat->find_next = find_next_push;
	while (true)
	{
		next_push_indx = dat->find_next(dat->sa, min, max, 'a');
		if (next_push_indx == dat->sa->len)
			return ;
		optimal_rrotation(dat, next_push_indx, 'a');
		check_n_store_ops(dat->sa, dat->sb, PB);
	}
}

static void	split_sb(t_data *dat, size_t min, size_t max)
{
	size_t	next_push_indx;
	size_t	range;

	range = max - min + 1;
	if (dat->sb->len == range)
		dat->find_next = find_next_push_empty;
	else
		dat->find_next = find_next_push;
	while (true)
	{
		next_push_indx = dat->find_next(dat->sb, min, max, 'b');
		if (next_push_indx == dat->sb->len)
			return ;
		optimal_rrotation(dat, next_push_indx, 'b');
		check_n_store_ops(dat->sa, dat->sb, PA);
	}
}

void	qsort_a(t_data *dat, size_t min, size_t max)
{
	size_t	range;

	range = max - min + 1;
	if (range <= 3)
	{
		sort_three_or_lower(dat, min, max);
		return ;
	}
	split_sa(dat, min, max);
	qsort_a(dat, (max + min + 1) / 2, max);
	qsort_b(dat, min, (max + min - 1) / 2);
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
			check_n_store_ops(dat->sa, dat->sb, RRB);
		i = range;
		while (i-- > 0)
			check_n_store_ops(dat->sa, dat->sb, PA);
		sort_three_or_lower(dat, min, max);
		return ;
	}
	split_sb(dat, min, max);
	qsort_a(dat, (max + min + 1) / 2, max);
	qsort_b(dat, min, (max + min - 1) / 2);
}
