/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/21 09:27:56 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/25 17:27:04 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philosopher(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	while (true)
	{
		if (check_if_done(philo))
			return (NULL);
		if (!ph_eat(philo))
			return (NULL);
		if (check_if_done(philo))
			return (NULL);
		ph_sleep(philo);
		if (check_if_done(philo))
			return (NULL);
		ph_think(philo);
	}
	return (NULL);
}

static void	thread_cleanup(t_dat *data, int actual_philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->stop_lock);
	data->stop = true;
	pthread_mutex_unlock(&data->stop_lock);
	while (i < actual_philos)
	{
		pthread_join(data->philos[i].t, NULL);
		pthread_mutex_destroy(&data->forks[i++]);
	}
	while (i < data->philo_num)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->stop_lock);
}

	//pthread_mutex_lock(&data->stop_lock);
	//if (data->stop)
	//{
	//	pthread_mutex_unlock(&data->stop_lock);
	//	return (false);
	//}
	//pthread_mutex_unlock(&data->stop_lock);
static bool	simulation_done(t_dat *data)
{
	int	i;
	int	finish_eating;

	i = 0;
	finish_eating = 0;
	while (i < data->philo_num)
	{
		if (data->philos[i].died)
			return (true);
		if (data->philos[i].times_eaten == data->must_eat)
			finish_eating++;
		i++;
	}
	if (finish_eating == data->philo_num)
		return (true);
	return (false);
}

int	simulate(t_dat *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->stop_lock, NULL);
	i = 0;
	if (gettimeofday(&data->sim_start, NULL) != 0)
		return (-1);
	while (i < data->philo_num)
	{
		data->philos[i].num = i;
		data->philos[i].data = data;
		data->philos[i].last_eaten = data->sim_start;
		data->philos[i].times_eaten = 0;
		data->philos[i].died = false;
		if (pthread_create(&data->philos[i].t, NULL, philosopher, &data->philos[i]) != 0)
		{
			thread_cleanup(data, i);
			return (-1);
		}
		i++;
	}
	while (!simulation_done(data))
		;
	thread_cleanup(data, data->philo_num);
	return (0);
}
