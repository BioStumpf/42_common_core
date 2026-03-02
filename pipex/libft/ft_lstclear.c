/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:28:46 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/27 14:18:20 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *lst, void (*del)(void *))
{
	t_node	*tmp;
	t_node	*next;

	if (!lst || !del)
		return ;
	next = lst->head;
	while (next)
	{
		tmp = next;
		next = tmp->next;
		ft_lstdelone(tmp, del);
	}
}
