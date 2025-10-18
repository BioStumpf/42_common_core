/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:04:49 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/12 13:08:12 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_next(t_list **lst_end, t_list *node)
{
	if (!*lst_end)
		*lst_end = node;
	else
	{
		(*lst_end)->next = node;
		*lst_end = (*lst_end)->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*new_end;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	new_end = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_node;
		ft_lstadd_next(&new_end, new_node);
		lst = lst->next;
	}
	return (new_list);
}
