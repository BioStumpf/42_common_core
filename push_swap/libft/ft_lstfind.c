/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:26:54 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/27 15:35:50 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstfind(t_list *lst, void *new_content, size_t n)
{
	t_node	*tmp;

	tmp = lst->head;
	while (tmp)
	{
		if (ft_memcmp(tmp->content, new_content, n) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
