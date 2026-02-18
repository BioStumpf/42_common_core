/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:25:57 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/18 20:56:21 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_sa(t_data *dat, size_t mid, size_t range)
{
	size_t	pushed;
	size_t	rotated;
	size_t	i;

	pushed = 0;
	rotated = 0;
	i = 0;
	while (i++ < range)
	{
		if (dat->sa->head->indx < mid)
		{
			push(dat->sa, dat->sb, 'b');
			pushed++;
		}
		else
		{
			rotate(dat->sa, 'a');
			rotated++;
		}
	}
	while (rotated-- && range < dat->sa->len)
		rrotate(dat->sa, 'a');
}

static void	split_sb(t_data *dat, size_t mid, size_t range)
{
	size_t	pushed;
	size_t	rotated;
	size_t	i;

	pushed = 0;
	rotated = 0;
	i = 0;
	while (i++ < range)
	{
		if (dat->sb->head->indx >= mid)
		{
			push(dat->sb, dat->sa, 'a');
			pushed++;
		}
		else
		{
			rotate(dat->sb, 'b');
			rotated++;
		}
	}
	while (rotated-- && range < dat->sb->len)
		rrotate(dat->sb, 'b');
}

void	qsort_a(t_data *dat, size_t min, size_t max)
{
	size_t	range;

	range = max - min + 1;
	if (range <= 3)
	{
		sort_three_or_lower(dat->sa, range);
		return ;
	}
	split_sa(dat, (max + min) / 2, range); 
	qsort_a(dat, (max + min) / 2, max);
	qsort_b(dat, min, (max + min) / 2 - 1);
}

void	qsort_b(t_data *dat, size_t min, size_t max)
{
	size_t	i;
	size_t	range;

	range = max - min + 1;
	if (range <= 3)
	{
		i = range;
		while (i-- > 0)
			push(dat->sb, dat->sa, 'a');
		sort_three_or_lower(dat->sa, range);
		return ;
	}
	split_sb(dat, (max + min) / 2, range); 
	qsort_a(dat, (max + min) / 2, max);
	qsort_b(dat, min, (max + min) / 2 - 1);
}
