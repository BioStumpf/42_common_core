/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lower6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:43:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/18 18:49:52 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three_or_lower(t_list *sa, size_t range)
{
	if (range == 2)
		sort_two(sa);
	else if (sa->len == 3)
		sort_three_empty(sa);
	else 
		sort_three_noempty(sa);
}

//bool	check_opt_sb(t_node *cur, t_node *prev, size_t target)
//{
//	if (cur->indx < target && target < prev->indx)
//		return (true);
//	if (cur->indx > prev->indx && (target > prev->indx || target < cur->indx))
//		return (true);
//	return (false);
//}
//

void	sort_five(t_data *dat)
{
//	dat->plan.ori = 'b';
//	dat->plan.dest = 'a';
//	dat->plan.f = check_opt_sa;
	while (dat->sa->len > 3)
		push(dat->sa, dat->sb, 'b');
	//sort_three_empty(dat->sa);
	sort_three_empty(dat->sa);
	while (dat->sb->len)
	{
		//dat->plan.target = dat->sb->head->indx;
		put_in_optimal_place(dat);
	}
	resort(dat->sa, 'a');
}
