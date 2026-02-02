/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lower5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:43:31 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/02 18:14:50 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list *sa)
{
	size_t	first;
	size_t	sec;
	size_t	last;

	first = sa->head->indx;
	sec = sa->head->next->next->indx;
	last = sa->tail->indx;
	if (first > sec && first > last)
		rotate(sa, 'a');
	else if (sec > first && sec > last)
		rrotate(sa, 'a');
	if (sa->head->indx > sa->head->next->indx)
		swap(sa, 'a');
}

void	sort_five(t_list *sa, t_list *sb)
{
	if (sa->len <= 1)
		return ;
	if (sa->len == 2)
	{
		swap(sa, 'a');
		return ;
	}
	while (sa->len > 3)
		push(sa, sb, 'b');
	sort_three(sa);
	if (sb->len == 2 && sb->head->indx > sb->head->next->indx)
		swap(sb, 'b');
	while (sb->len)
		push(sb, sa, 'a');
}
