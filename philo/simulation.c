/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/21 09:27:56 by dstumpf             #+#    #+#             */
/*   Updated: 2026/07/20 15:02:22 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void	init_thread(t_dat *data, int i)
{
	data->philos[i].last_eaten = data->sim_start;
	data->philos[i].num = i;
	data->philos[i].data = data;
	data->philos[i].times_eaten = 0;
	data->philos[i].died = false;
	pthread_mutex_init(&data->philos[i].lock, NULL);
}

static bool	start_simulation(t_dat *data)
{
	int	i;

	i = -1;
	if (gettimeofday(&data->sim_start, NULL) != 0)
		return (false);
	while (++i < data->philo_num)
		data->philos[i].last_eaten = data->sim_start;
	start_sim(data);
	return (true);
}

static bool	init_mutex(t_dat *data, int *i)
{
	while (++(*i) < data->philo_num)
		if (pthread_mutex_init(&data->forks[*i], NULL) != 0)
			return (false);
	if (pthread_mutex_init(&data->stop_lock, NULL) != 0)
		return (false);
	return (true);
}

static void	*phil(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	wait_for_start(philo);
	if (philo->num % 2)
		usleep(philo->data->eat_time / 2);
	while (true)
	{
		if (!ph_eat(philo))
			return (NULL);
		if (!ph_sleep(philo))
			return (NULL);
		if (!ph_think(philo))
			return (NULL);
	}
	return (NULL);
}

int	simulate(t_dat *data)
{
	int	i;

	i = -1;
	if (!init_mutex(data, &i))
		return (sim_cleanup(data, 0, i), -1);
	i = -1;
	while (++i < data->philo_num)
	{
		init_thread(data, i);
		if (pthread_create(&data->philos[i].t, NULL, phil, &data->philos[i]))
			return (sim_cleanup(data, i, data->philo_num), -1);
	}
	if (!start_simulation(data))
		return (sim_cleanup(data, data->philo_num, data->philo_num), -1);
	while (!simulation_done(data))
		usleep(1000);
	sim_cleanup(data, data->philo_num, data->philo_num);
	return (0);
}
