/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/25 19:41:57 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	print_operations(size_t *prev)
{
	while (prev[RA]--)
		ft_printf("ra\n");
	while (prev[RB]--)
		ft_printf("rb\n");
	while (prev[RRA]--)
		ft_printf("rra\n");
	while (prev[RRB]--)
		ft_printf("rrb\n");
	while (prev[PA]--)
		ft_printf("pa\n");
	while (prev[PB]--)
		ft_printf("pb\n");
	prev[RA] = 0;
	prev[RB] = 0;
	prev[RRA] = 0;
	prev[RRB] = 0;
	prev[PA] = 0;
	prev[PB] = 0;
}

static void	print_operation(int select)
{
	if (select == RA)
		ft_printf("ra\n");
	else if (select == RB)
		ft_printf("rb\n");
	else if (select == RRA)
		ft_printf("rra\n");
	else if (select == RRB)
		ft_printf("rrb\n");
	else if (select == SA)
		ft_printf("sa\n");
	else if (select == PA)
		ft_printf("pa\n");
	else if (select == PB)
		ft_printf("pb\n");
}

static void	do_operation(t_list *sa, t_list *sb, int select)
{
	if (select == RA)
		rotate(sa);
	else if (select == RB)
		rotate(sb);
	else if (select == RRA)
		rrotate(sa);
	else if (select == RRB)
		rrotate(sb);
	else if (select == SA)
		swap(sa);
	else if (select == PA)
		push(sb, sa);
	else if (select == PB)
		push(sa, sb);
}

void	check_n_store_ops(t_list *sa, t_list *sb, int select)
{
	static size_t	prev[6];

	do_operation(sa, sb, select);
	if (stop_accumulation(select, prev))
	{
		trim_redundant_moves(prev);
		combine_rrots(prev);
		print_operations(prev);
		print_operation(select);
	}
	else
		prev[select]++;
}
