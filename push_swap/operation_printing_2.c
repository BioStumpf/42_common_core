/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_printing_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:28 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/25 19:50:32 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	trim_redundant_moves(size_t *prev)
{
	while (prev[PA] && prev[PB])
	{
		prev[PA]--;
		prev[PB]--;
	}
	while (prev[RA] && prev[RRA])
	{
		prev[RA]--;
		prev[RRA]--;
	}
	while (prev[RB] && prev[RRB])
	{
		prev[RB]--;
		prev[RRB]--;
	}
}

void	combine_rrots(size_t *prev)
{
	while (prev[RA] && prev[RB])
	{
		prev[RA]--;
		prev[RB]--;
		ft_printf("rr\n");
	}
	while (prev[RRA] && prev[RRB])
	{
		prev[RRA]--;
		prev[RRB]--;
		ft_printf("rrr\n");
	}
}

bool	stop_accumulation(int select, size_t *prev)
{
	if (select == SA || select == STOP)
		return (true);
	if ((select == RA || select == RB || select == RRA
			|| select == RRB) && (prev[PA] || prev[PB]))
		return (true);
	if ((select == PA || select == PB) && (prev[RA]
			|| prev[RB] || prev[RRA] || prev[RRB]))
		return (true);
	return (false);
}
