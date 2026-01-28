/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:34:52 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/28 14:39:38 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_node *node))
{
	t_node	*tmp;

	tmp = lst->head;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}
