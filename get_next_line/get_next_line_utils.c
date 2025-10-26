/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:08:16 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/26 16:49:17 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_glob_stash(t_fdlist *glob_stash)
{
	if (!glob_stash)
		return ;
	free_glob_stash(glob_stash->next);
//	free(glob_stash->line);
	free(glob_stash);
}

t_fdlist	*new_stash(int fd)
{
	t_fdlist	*new;

	new = malloc(sizeof(t_fdlist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->fd = fd;
	return (new);
}

t_fdlist	*add_stash(t_fdlist **glob_stash, int fd)
{
	t_fdlist	*stash;

	stash = new_stash(fd);
	if (!stash)
		return (NULL);
	if (!*glob_stash)
		*glob_stash = stash;
	else
	{
		stash->next = *glob_stash;
		*glob_stash = stash;
	}
	return (stash);
}

t_fdlist	*find_stash(t_fdlist *stash, int fd)
{
	while (stash)
	{
		if (fd == stash->fd)
			return (stash);
		stash = stash->next;
	}
	return (NULL);
}

t_fdlist	*get_fd_stash(t_fdlist **glob_stash, int fd)
{
	t_fdlist	*stash;

	stash = find_stash(*glob_stash, fd);
	if (!stash)
		stash = add_stash(glob_stash, fd);
	if (!stash)
		return (NULL);
	return (stash);
}
