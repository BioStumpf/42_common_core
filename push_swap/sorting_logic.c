/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:56:07 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/02 18:18:47 by dstumpf          ###   ########.fr       */
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

static bool	better_candidate(size_t idx, size_t best, size_t stack_len)
{
	if (moves_to_top(idx, stack_len) < moves_to_top(best, stack_len))
		return (true);
	return (false);
}

static size_t	find_next_push_a(t_data *dat)
{
	t_node	*tmp;
	size_t	best;
	size_t	i;

	i = 0;
	best = dat->sa->len / 2;
	tmp = dat->sa->head;
	while (tmp)
	{
		if (tmp->indx < dat->sa_min + dat->chunk_s)
		{
			if (better_candidate(i, best, dat->sa->len))
				best = i;
		}
		tmp = tmp->next;
		++i;
	}
	return (best);
}

static size_t	find_next_push_sb(t_list *sb)
{
	t_node	*tmp;
	size_t	target;
	size_t	target_idx;
	size_t	i;

	i = 0;
	target = 0;
	tmp = sb->head;
	while (tmp)
	{
		if (tmp->indx > target)
		{
			target = tmp->indx;
			target_idx = i;
		}
		tmp = tmp->next;
		++i;
	}
	return (target_idx);
}

static bool	check_rotate_b(t_list *sb)
{
	size_t	next;

	next = find_next_push_sb(sb);
	if (next != 0 && (next < sb->len / 2))
		return (true);
	return (false);
}

static void	do_next_push(t_list *ori, t_list *dest, size_t idx, char ori_id, char dest_id)
{
	size_t	i;
	size_t	mid;
	size_t	ops;

	i = 0;
	mid = ori->len / 2;
	if (idx == 0)
	{
		push(ori, dest, dest_id);
		return ;
	}
	if (idx > mid || (ori->len % 2 && idx == mid))
	{
		ops = ori->len - idx;
		while (i++ < ops)
			rrotate(ori, ori_id);
	}
	else
	{
		ops = idx;
		while (i++ < ops)
		{
			if (ori_id == 'a' && check_rotate_b(dest))
				rot_or_rrot_both(ori, dest, FOR);
			else
			rotate(ori, ori_id);
		}
	}
	push(ori, dest, dest_id);
}

void	sort_to_sa(t_data *dat)
{
	size_t	next;

	while (dat->sb->len)
	{
		next = find_next_push_sb(dat->sb);
		do_next_push(dat->sb, dat->sa, next, 'b', 'a');
	}
}

void	chunks_to_sb(t_data *dat)
{
	size_t	next;
	size_t	i;

	i = 0;
	if (dat->sa->len < 6)
		sort_five(dat->sa, dat->sb);
	while (dat->sa->len)
	{
		next = find_next_push_a(dat);
		do_next_push(dat->sa, dat->sb, next, 'a', 'b');
		++i;
		if (i == dat->chunk_s)
		{
			dat->sa_min = dat->sa_min + dat->chunk_s;
			i = 0;
		}
	}
}

//void	chunks_to_sb(t_data *dat)
//{
//	size_t	i;
//
//	i = 0;
//	while (dat->sa->len)
//	{
//		if (dat->sa->head->indx < dat->sa_min + dat->chunk_s)
//		{
//			push(dat->sa, dat->sb, 'b');
//			if (++i == dat->chunk_s)
//			{
//				dat->sa_min += dat->chunk_s;
//				i = 0;
//			}
//		}
//		else
//		{
//			if (check_rotate_b(dat->sb))
//				rot_or_rrot_both(dat->sa, dat->sb, FOR);
//			else
//				rotate(dat->sa, 'a');
//		}
//	}
//}
