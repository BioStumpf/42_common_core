/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:50:15 by dstumpf           #+#    #+#             */
/*   Updated: 2026/01/12 16:29:35 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void	print_lst_str(void *content)
//{
//	ft_printf("%s", (char *)content);
//}

//static void	print_grid(t_grid *grid)
//{
//	t_point	**mat;
//	int		i;
//	int		j;
//
//	mat = grid->mat;
////	ft_printf("Rows: %d\n", grid->rows);
////	ft_printf("Cols: %d\n", grid->cols);
//	i = 0;
//	while (i < grid->rows)
//	{
//		j = 0;
//		while (j < grid->cols)
//		{
//			//dont use printf!!!!!!
//			printf("x_iso:%.2f y_iso:%.2f   ", mat[i][j].x, mat[i][j].y);
//			j++;
//		}
//		printf("\n\n");
//		i++;
//	}
//}

t_grid	*parse_map(int fd)
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
//	t_list	*lst;
	if (argc != 2)
		exit_error("Provide one argument.", EINVAL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open file.", errno);
//	lst = read_map_lst(fd);
//	ft_printf("lst len: %u\n", lst->len);
//	ft_lstprint(lst, print_lst_str);
//	ft_lstclear(lst, free);
	grid = parse_map(fd);
	scale_points(grid);
//	print_grid(grid);
	display_grid(grid);
	free_grid(grid);
	close(fd);
	return (0);
}
