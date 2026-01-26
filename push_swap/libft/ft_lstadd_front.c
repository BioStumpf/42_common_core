/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:09:33 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/28 11:14:13 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list *lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = lst->head;
	lst->head = new;
	if (!lst->tail)
		lst->tail = new;
	lst->len++;
}
