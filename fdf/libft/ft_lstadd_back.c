/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:45:32 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/28 12:03:46 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (!lst->tail)
	{
		lst->tail = new;
		lst->head = new;
	}
	else
	{
		lst->tail->next = new;
		lst->tail = new;
	}
	lst->len++;
}
