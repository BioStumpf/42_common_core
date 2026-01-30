/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:50:53 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/27 19:58:33 by dstumpf          ###   ########.fr       */
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

typedef struct s_data
{
	t_list	*sa;
	t_list	*sb;
	size_t	chunk_s;
	size_t	sa_min;
	size_t	sb_max;
}			t_data;

bool	parse_inpt(int ac, char **av, t_list *lst);
void	swap(t_list *lst, char stack);
void	swap_both(t_list *sa, t_list *sb);
void	rrotate(t_list *lst, char stack);
void	rotate(t_list *lst, char stack);
void	rot_or_rrot_both(t_list *a, t_list *b, int direction);
void	push(t_list *origin, t_list *dest, char dest_stack);
void	chunks_to_sb(t_data *dat);

#endif
