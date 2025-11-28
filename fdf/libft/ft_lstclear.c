/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:28:46 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/26 15:04:23 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear_rec(t_node *node, void (*del)(void *))
{
	if (!node)
		return ;
	ft_lstclear_rec(node->next, del);
	ft_lstdelone(node, del);
}

void	ft_lstclear(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	ft_lstclear_rec(lst->head, del);
	free(lst);
}
