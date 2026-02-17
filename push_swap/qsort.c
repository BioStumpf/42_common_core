/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:25:57 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/17 19:00:17 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_to_sb(t_data *dat, size_t mid, size_t *pushed)
{
	if (dat->sa->head->indx < mid)
	{
		push(dat->sa, dat->sb, 'b');
		*pushed += 1;
	}
	else
		rotate(dat->sa, 'a');
}

static void	split_halves(t_data *dat, size_t range, size_t mid)
{
	size_t	pushed;

	pushed = 0;
	while (pushed < range / 2)
		dat->f(dat, mid, &pushed);
}

void	qsort_a(t_data *dat, size_t range, size_t mid)
{
	if (range <= 3)
	{
		sort_three_or_lower(dat->sa, range);
		return ;
	}
	dat->f = sa_to_sb;
	split_halves(dat, range, mid);
	if (range % 2)
		qsort_a(dat, range / 2 + 1, mid + mid / 2 + 1);
	else
		qsort_a(dat, range / 2, mid + mid / 2);
	// dat->f = sb_to_sa;
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
