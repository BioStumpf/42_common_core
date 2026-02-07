/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:50:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/02/07 15:39:13 by dstumpf          ###   ########.fr       */
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

//typedef struct s_insert_plan
//{
//	char	ori;
//	char	dest;
//	size_t	target;
//	bool	(*f)(t_node *cur, t_node *prev, size_t target);
//}			t_insert_plan;

typedef struct s_rec_dat
{
	size_t	range;
	size_t	mid;
}			t_rec_dat;

typedef struct s_data
{
	//t_insert_plan	plan;
	t_list			*sa;
	t_list			*sb;
	void			*(f)(t_data *dat, t_rec_dat *rec, size_t idx);
	//size_t			chunk_s;
	//size_t			sa_min;
	//size_t			sb_max;
}					t_data;

//input handling
bool	parse_inpt(int ac, char **av, t_list *lst);
//stack operations
void	swap(t_list *lst, char stack);
void	swap_both(t_list *sa, t_list *sb);
void	rrotate(t_list *lst, char stack);
void	rotate(t_list *lst, char stack);
void	rot_or_rrot_both(t_list *a, t_list *b, int direction);
void	push(t_list *origin, t_list *dest, char dest_stack);
//sorting
void	chunks_to_sb(t_data *dat);
void	sort_to_sa(t_data *dat);
void	sort_five(t_data *dat);
void	sort_three_or_lower(t_list *sa, size_t range);
//helpers for sorting
void	optimal_rrotation(t_list *stack, size_t idx, char id);
void	put_in_optimal_place(t_data *dat);
void	resort(t_list *stack, char id);
//bool	check_opt_sa(t_node *cur, t_node *prev, size_t target);
//bool	check_opt_sb(t_node *cur, t_node *prev, size_t target);

#endif
