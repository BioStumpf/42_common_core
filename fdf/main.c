/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:50:15 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/25 19:45:02 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_complete.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		**grid;

	if (argc != 2)
		return (1);
	fd = open(map, O_RDONLY);
	grid = parse_input(fd);	
	close(fd);
	return (0);
}
