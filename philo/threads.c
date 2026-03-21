/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/21 09:27:56 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/21 20:08:09 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philosopher(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	pickup_fork(philo);
	return (NULL);
}

static void	thread_cleanup(t_dat *data, int actual_philos)
{
	int	i;

	//pthread_mutex_lock(&data->stop_lock);
	//data->stop = 1;
	//pthread_mutex_unlock(&data->stop_lock);
	i = 0;
	while (i < actual_philos)
		pthread_join(data->philos[i++].t, NULL);
	i = 0;
	while (i < data->philo_num)
		pthread_mutex_destroy(&data->forks[i++]);
}

int	start_simulation(t_dat *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].num = i;
		data->philos[i].data = data;
		if (pthread_create(&data->philos[i].t, NULL, philosopher, &data->philos[i]) != 0)
		{
			thread_cleanup(data, i);
			return (-1);
		}
		i++;
	}
	//while (all_alive(data) == 0)
	//	;
	thread_cleanup(data, data->philo_num);
	return (0);
}
