/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:47:51 by dstumpf           #+#    #+#             */
/*   Updated: 2025/10/18 12:54:43 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*next_line;

	next_line = malloc(BUFFER_SIZE);
	if (!next_line)
		return (NULL);
	read_line(&next_line, fd);
	return (next_line);
}
