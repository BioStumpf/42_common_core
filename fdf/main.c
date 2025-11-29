/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:50:15 by dstumpf           #+#    #+#             */
/*   Updated: 2025/11/29 15:11:42 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void	print_lst_str(void *content)
//{
//	ft_printf("%s", (char *)content);
//}

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*map;
	t_grid	**grid;

	if (argc != 2)
	{
		errno = EINVAL; 
		exit_error("Provide two arguments.");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open file.");
	grid = parse_input(fd);	
	if (close(fd) < 0)
		exit_error("Failed to close file.");
	return (0);
}
