/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:50:15 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/19 19:10:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_grid	*parse_map(int fd)
{
	t_list	*map_lst;
	t_grid	*grid;

	map_lst = read_map_lst(fd);
	close(fd);
	grid = make_grid(map_lst);
	ft_lstclear(map_lst, free);
	return (grid);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_grid	*grid;

	if (argc != 2)
		exit_error("Provide one argument.", EINVAL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open file.", errno);
	grid = parse_map(fd);
	
	display_grid(grid);
	free_grid(grid);
	return (0);
}
