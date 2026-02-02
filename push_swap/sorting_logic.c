/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:56:07 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/02 09:52:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	moves_to_top(size_t idx, size_t stack_len)
{
	size_t	mid;

	mid = stack_len / 2;
	if (idx > mid || (stack_len % 2 && idx == mid))
		return (stack_len - idx);
	return (idx);
}

//static bool	better_candidate(size_t idx, size_t best, size_t stack_len)
//{
//	if (moves_to_top(idx, stack_len) < moves_to_top(best, stack_len))
//		return (true);
//	return (false);
//}

static bool	better_candidate(t_data *dat, size_t idx, size_t best)
{
	if (moves_to_top(idx, dat->sb->len) < moves_to_top(best, dat->sb->len))
		return (true);
	return (false);
}

static size_t	find_next_push(t_data *dat, bool (*f)(t_data *dat, size_t idx, size_t best))
{
	t_node	*tmp;
	size_t	best;
	size_t	i;

	i = 0;
	best = dat->sa->len / 2;
	tmp = dat->sa->head;
	while (tmp)
	{
		if (f(dat, i, best))
			best = i;
		//if (tmp->indx < dat->sa_min + dat->chunk_s)
		//{
		//	if (better_candidate(i, best, dat->sa->len))
		//		best = i;
		//}
		tmp = tmp->next;
		++i;
	}
	return (best);
}

//static bool	check_sb_move()
//{
//}

//crosslink do_next_push() to also r/rotate sb (rr/rrr if possible)
static void	do_next_push(t_data *dat, size_t idx)
{
	size_t	i;
	size_t	mid;
	size_t	ops;

	i = 0;
	mid = dat->sb->len / 2;
	if (dat->sb->len < 2)
	{
		push(dat->sb, dat->sa, 'a');
		return ;
	}
	if (idx > mid || (dat->sb->len % 2 && idx == mid))
	{
		ops = dat->sb->len - idx;
		while (i++ < ops)
			rrotate(dat->sb, 'b');
	}
	else
	{
		ops = idx;
		while (i++ < ops)
			rotate(dat->sb, 'a');
	}
	push(dat->sb, dat->sa, 'a');
}

void	sort_to_sa(t_data *dat)
{
	size_t	next;

	while (dat->sb->len)
	{
		next = find_next_push(dat, better_candidate);
		do_next_push(dat, next);
	}
}

void	chunks_to_sb(t_data *dat)
{
	size_t	i;

	i = 0;
	while (dat->sa->len)
	{
		if (dat->sa->head->indx < dat->sa_min + dat->chunk_s)
		{
			push(dat->sa, dat->sb, 'b');
			if (++i == dat->chunk_s)
			{
				dat->sa_min = dat->sa_min + dat->chunk_s;
				i = 0;
			}
		}
		else
			rotate(dat->sa, 'a');
	}
}

//void	chunks_to_sb(t_data *dat)
//{
//	size_t	next;
//	size_t	i;
//
//	i = 0;
//	while (dat->sa->len)
//	{
//		next = find_next_push(dat);
//		do_next_push(dat, next);
//		++i;
//		if (i == dat->chunk_s)
//		{
//			dat->sa_min = dat->sa_min + dat->chunk_s;
//			i = 0;
//		}
//	}
//}

//void	sort_chunks_to_sa()
//{
//	size_t	next;
//
//	while (dat->sa->len)
//	{
//		next = find_next_push(dat, size);
//		do_next_push(sa, sb, next);
//	}
//}
