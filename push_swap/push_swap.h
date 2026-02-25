/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:50:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/25 19:50:30 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"

# define FOR 1
# define REV -1
# define RA 0
# define RB 1 
# define RRA 2 
# define RRB 3 
# define PA 4 
# define PB 5 
# define SA 6 
# define STOP 7

typedef struct s_data
{
	t_list			*sa;
	t_list			*sb;
}					t_data;

//input handling
bool	parse_inpt(int ac, char **av, t_list *lst);
//stack operations
void	swap(t_list *lst);
void	rrotate(t_list *lst);
void	rotate(t_list *lst);
void	push(t_list *origin, t_list *dest);
void	check_n_store_ops(t_list *sa, t_list *sb, int select);
//sorting
size_t	targets_at_bottom(t_list *stack, size_t min, size_t max);
void	sort_three_or_lower(t_data *dat, size_t min, size_t max);
void	qsort_a(t_data *dat, size_t min, size_t max);
void	qsort_b(t_data *dat, size_t min, size_t max);
//sorting helpers
size_t	find_next_push(t_list *stack, size_t min, size_t max, char s_id);
void	optimal_rrotation(t_data *dat, size_t idx, char stack);
//printing the stack operations
//helpers
bool	stop_accumulation(int select, size_t *prev);
void	combine_rrots(size_t *prev);
void	trim_redundant_moves(size_t *prev);

#endif
