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
			rrotate(dat->sb, 'b');
		i = range;
		while (i-- > 0)
			push(dat->sb, dat->sa, 'a');
		sort_three_or_lower(dat->sa, min, max);
		return ;
	}
	split_sb(dat, min, max); 
	qsort_a(dat, (max + min + 1) / 2, max);
	qsort_b(dat, min, (max + min - 1) / 2);
}
