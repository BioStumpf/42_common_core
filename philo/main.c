/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:06:34 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/20 15:51:07 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_data(t_dat *data, int ac, char **av)
{
	int	err;

	err = 0;
	data->philo_num = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1; 
	return (0);
}

static int	fetch_args(t_dat *data, int ac, char **av)
{
	if (5 > ac || ac > 6)
		return (-1);
	if (init_data(data, ac, av) == -1)
		return (-1);
	return (0);
}

int main(int ac, char **av)
{
	t_dat	data;

	if (fetch_args(&data, ac, av) == -1)
		return (1);
	return (0);
}
