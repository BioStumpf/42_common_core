/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lower6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:43:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/04 19:15:51 by dstumpf          ###   ########.fr       */
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

bool	check_opt_sa(t_node *cur, t_node *prev, size_t target)
{
	if (cur->indx > target && target > prev->indx)
		return (true);
	if (cur->indx < prev->indx && (target < prev->indx || target > cur->indx))
		return (true);
	return (false);
}

//bool	check_opt_sb(t_node *cur, t_node *prev, size_t target)
//{
//	if (cur->indx < target && target < prev->indx)
//		return (true);
//	if (cur->indx > prev->indx && (target > prev->indx || target < cur->indx))
//		return (true);
//	return (false);
//}

void	sort_five(t_data *dat)
{
	dat->plan.ori = 'b';
	dat->plan.dest = 'a';
	dat->plan.f = check_opt_sa;
	if (dat->sa->len == 2)
	{
		swap(dat->sa, 'a');
		return ;
	}
	while (dat->sa->len > 3)
		push(dat->sa, dat->sb, 'b');
	sort_three(dat->sa);
	while (dat->sb->len)
	{
		dat->plan.target = dat->sb->head->indx;
		put_in_optimal_place(dat);
	}
	resort(dat->sa, 'a');
}
