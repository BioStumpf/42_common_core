/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:28:46 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/10 17:35:16 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear_rec(t_list *lst_cursor, void (*del)(void *))
{
	if (!lst_cursor)
		return ;
	ft_lstclear_rec(lst_cursor->next, del);
	ft_lstdelone(lst_cursor, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	ft_lstclear_rec(*lst, del);
	*lst = NULL;
}
