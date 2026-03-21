/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:06:34 by dstumpf           #+#    #+#             */
/*   Updated: 26/03/21 15:49:15 by dstumpf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
//#include <stdio.h>

static int	cleanup(t_dat *data)
{
	free(data->philos);
	free(data->forks);
	return (-1);
}

static int	init_data(t_dat *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_dat));
	data->philo_num = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1; 
	if (data->philo_num <= 0 || data->die_time < 0 || data->eat_time < 0
	 || data->sleep_time < 0)
		return (-1);
	data->philos = malloc(data->philo_num * (sizeof(t_philo)));
	data->forks = malloc(data->philo_num * (sizeof(pthread_mutex_t)));
	if (!data->philos || !data->forks)
		return (cleanup(data));
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
	start_simulation(&data);	
	cleanup(&data);
	return (0);
}
