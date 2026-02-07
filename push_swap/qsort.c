/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:25:57 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/07 15:41:08 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_to_sb(t_data *dat, t_rec_dat *rec, size_t idx)
{
	if (idx <= rec->mid)
		push(dat->sa, dat->sb, 'b');
}

static void	split_halves(t_data *dat, t_rec_dat *rec)
{
	size_t	i;

	i = 0;
	while (i++ < rec->range)
		rec->f(dat, rec, i);
}

void	qsort_a(t_data *dat, size_t range, size_t mid)
{
	if (range < 3)
	{
		sort_three_or_lower(dat->sa, range);
		return ;
	}
	dat->f = sa_to_sb;
	split_halves(&rec, sa_to_sb);
	qsort_a(dat, rec.range / 2, rec.mid + rec.mid / 2);
	dat->f = sb_to_sa;
	//qsort_b(dat, range / 2, mid - mid / 2);
}

//void	qsort_b(t_data *dat, size_t range)
//{
//	if (range < 3)
//	{
//		put_in_optimal_place(dat);
//		return ;
//	}
//	split_halves(&rec, sb_to_sa);
//	qsort_a(dat, range / 2);
//	qsort_b(dat, range / 2);
//}
