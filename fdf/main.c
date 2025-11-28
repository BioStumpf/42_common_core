/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:50:15 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/28 17:52:26 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_lst_str(void *content)
{
	ft_printf("%s", (char *)content);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*map;
	t_grid	**grid;

	if (argc != 2)
		exit_error("Nr. of args must be 2!");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error(strerror(errno));
	grid = parse_input(fd);	
	if (close(fd) < 0)
		exit_error(strerror(errno));
	return (0);
}
