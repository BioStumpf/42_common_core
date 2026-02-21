/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/19 16:01:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	push(t_list *origin, t_list *dest, char dest_stack)
{
	t_node	*tmp;

	if (origin->len <= 0)
		return ;
	tmp = origin->head;
	origin->head = origin->head->next;
	if (!origin->head)
		origin->tail = NULL;
	tmp->next = dest->head;
	dest->head = tmp;
	if (!dest->tail)
		dest->tail = tmp;
	origin->len--;
	dest->len++;
	ft_printf("p%c\n", dest_stack);
}

static void	trim_redundant_moves(size_t *prev)
{
	while (prev[PA] && prev[PB])
	{
		prev[PA]--;
		prev[PB]--;
	}
	while (prev[RA] && prev[RRA])
	{
		prev[RA]--
		prev[RRA]--
	}
	while (prev[RB] && prev[RRB])
	{
		prev[RB]--
		prev[RRB]--
	}
}

static void	combine_rrots(t_list *sa, t_list *sb, size_t *prev)
{
	while (prev[RA] && prev[RB])
	{
		prev[RA]--;
		prev[RB]--;
		rot_or_rrot_both(sa, sb, FOR);
	}
	while (prev[RA]--)
		rotate(sa, 'a');
	while (prev[RB]--)
		rotate(sb, 'b');
	while (prev[RRA]-- && prev[RRB]--)
	{
		prev[RRA]--;
		prev[RRB]--;
		rot_or_rrot_both(sa, sb, REV);
	}
	while (prev[RRA]--)
		rrotate(sa, 'a');
	while (prev[RRB]--)
		rrotate(sb, 'b');
}

static bool	stop_accumulation(int select, size_t *prev)
{
	if (select == SA || select == STOP)
		return (true);
	if ((select == RA || select == RB || select == RRA || select == RRB) && (prev[PA] || prev[PB]))
		return (true);
	if ((select == PA || select == PB) && (prev[RA] || prev[RB] || prev[RRA] || prev[RRB]))
		return (true);
}

static void	do_operation(t_list *sa, t_list *sb, int select)
{
	if (select == RA)
		rotate(sa, 'a');
	if (select == RB)
		rotate(sb, 'b');
	if (select == SA)
		swap(sa, 'a');
	if (select == PA)
		push(sb, sa, 'a');
	if (select == PB)
		push(sa, sb, 'b');
}

void	check_n_store_ops(t_list *sa, t_list *sb, int select)
{
	static size_t	prev[6];

	if (stop_accumulation(select, prev))
	{
		trim_redundant_moves(prev);
		combine_rrots(sa, sb, prev);
		do_operation(sa, sb, select);
	}
	else
		prev[select]++;
}
