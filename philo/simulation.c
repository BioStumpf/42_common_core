/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/21 09:27:56 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/24 16:53:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philosopher(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	while (!philo->data->stop)
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (NULL);
}

static void	thread_cleanup(t_dat *data, int actual_philos)
{
	int	i;

	pthread_mutex_lock(&data->stop_lock);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_lock);
	i = 0;
	while (i < actual_philos)
	{
		pthread_join(data->philos[i].t, NULL);
		pthread_mutex_destroy(&data->forks[i++]);
	}
	while (i < data->philo_num)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->stop_lock);
}

//static int	all_alive(t_dat *data)
//{
//	int	i;
//
//	i = 0;
//	while (i < data->philo_num)
//	{
//		if (data->philos[i++].done)
//			return (-1);
//	}
//	return (0);
//}

int	simulate(t_dat *data)
{
	int				i;
	struct timeval	start;

	i = 0;
	while (i < data->philo_num)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->stop_lock, NULL);
	i = 0;
	if (gettimeofday(&start, NULL) != 0)
		return (-1);
	while (i < data->philo_num)
	{
		data->philos[i].num = i;
		data->philos[i].data = data;
		data->philos[i].done = false;
		data->philos[i].last_eaten = start;
		if (pthread_create(&data->philos[i].t, NULL, philosopher, &data->philos[i]) != 0)
		{
			thread_cleanup(data, i);
			return (-1);
		}
		i++;
	}
	usleep(5);
	//while (all_alive(data) == 0)
	//	;
	thread_cleanup(data, data->philo_num);
	return (0);
}
