#include "push_swap.h"

//static size_t	moves_to_top(size_t idx, size_t stack_len)
//{
//	size_t	mid;
//
//	mid = stack_len / 2;
//	if (idx > mid || (stack_len % 2 && idx == mid))
//		return (stack_len - idx);
//	return (idx);
//}
//
//static bool	better_candidate(size_t indx, size_t best, size_t stack_len)
//{
//	if (moves_to_top(indx, stack_len) < moves_to_top(best, stack_len))
//		return (true);
//	return (false);
//}
//
//static size_t	find_next_push(t_data *dat)
//{
//	t_node	*tmp;
//	size_t	best;
//	size_t	i;
//
//	i = 0;
//	best = dat->sa->len / 2;
//	tmp = dat->sa->head;
//	while (tmp)
//	{
//		if (tmp->indx < dat->sa_min + dat->chunk_s)
//		{
//			if (better_candidate(i, best, dat->sa->len))
//				best = i;
//		}
//		tmp = tmp->next;
//		++i;
//	}
//	return (best);
//}
//
////static bool	check_sb_move()
////{
////}
//
////crosslink do_next_push() to also r/rotate sb (rr/rrr if possible)
//static void	do_next_push(t_data *dat, size_t idx)
//{
//	size_t	i;
//	size_t	mid;
//	size_t	ops;
//
//	i = 0;
//	mid = dat->sa->len / 2;
//	if (idx > mid || (dat->sa->len % 2 && idx == mid))
//	{
//		ops = dat->sa->len - idx;
//		while (i++ < ops)
//			rrotate(dat->sa, 'a');
//	}
//	else
//	{
//		ops = idx;
//		while (i++ < ops)
//			rotate(dat->sa, 'a');
//	}
//	push(dat->sa, dat->sb, 'b');
//}

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
