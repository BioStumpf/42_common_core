/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:25:57 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/05 11:54:49 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static size_t	find_middle(t_list *stack);
static void	split_halves();

void	qsort_a(t_data *dat, size_t range, size_t mid)
{
	if (range < 3)
	{
		sort_three(dat->sa);
		return ;
	}
	split(dat, range, mid);
	qsort_a(dat, range / 2, mid + mid / 2);
	//qsort_b(dat, range / 2, mid - mid / 2);
}

//void	qsort_b(t_data *dat, size_t range)
//{
//	if (range < 3)
//	{
//		put_in_optimal_place(dat);
//		return ;
//	}
//	split_halves(dat, range);
//	qsort_a(dat, range / 2);
//	qsort_b(dat, range / 2);
//}
