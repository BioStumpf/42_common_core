/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/21 09:27:56 by dstumpf             #+#    #+#             */
/*   Updated: 2026/07/17 15:14:10 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

static void	wait_for_start(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_lock);
	while (!philo->data->start)
	{
	    pthread_mutex_unlock(&philo->data->stop_lock);
	    usleep(20);
	    pthread_mutex_lock(&philo->data->stop_lock);
	}
	pthread_mutex_unlock(&philo->data->stop_lock);
}

static void	*philosopher(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	wait_for_start(philo);
	while (true)
	{
		if (philo->num % 2)
		{
			if (!ph_eat(philo))
				return (NULL);
			if (!ph_sleep(philo))
				return (NULL);
			if (!ph_think(philo))
				return (NULL);
		}
		else
		{
			if (!ph_think(philo))
				return (NULL);
			if (!ph_eat(philo))
				return (NULL);
			if (!ph_sleep(philo))
				return (NULL);
		}
	}
	return (NULL);
}

static void	print_death(t_philo *philo)
{
	printf("%lu %d died\n", get_rel_time(&philo->data->sim_start), philo->num + 1);
}

static void	stop_sim(t_dat *data)
{
	pthread_mutex_lock(&data->stop_lock);
	data->stop = true;
	pthread_mutex_unlock(&data->stop_lock);
}

static void	start_sim(t_dat *data)
{
	pthread_mutex_lock(&data->stop_lock);
	data->start = true;
	pthread_mutex_unlock(&data->stop_lock);
}

static void	thread_cleanup(t_dat *data, int actual_philos)
{
	int	i;

	i = 0;
	stop_sim(data);
	start_sim(data);
	while (i < actual_philos)
	{
		pthread_join(data->philos[i].t, NULL);
		pthread_mutex_destroy(&data->philos[i].lock);
		pthread_mutex_destroy(&data->forks[i++]);
	}
	while (i < data->philo_num)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->stop_lock);
}

static bool	finished_eating(t_philo *philo)
{
	return (philo->data->must_eat != -1
		&& philo->times_eaten >= philo->data->must_eat);
}

static bool	simulation_done(t_dat *data)
{
	int		i;
	int		finish_eating;
	t_philo	*philo;

	i = 0;
	finish_eating = 0;
	while (i < data->philo_num)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->lock);
		if (died(philo))
		{
			pthread_mutex_lock(&data->stop_lock);
			data->stop = true;
			print_death(philo);
			pthread_mutex_unlock(&data->stop_lock);
			pthread_mutex_unlock(&philo->lock);
			return (true);
		}
		if (finished_eating(philo))
			finish_eating++;
		pthread_mutex_unlock(&philo->lock);
		i++;
	}
	if (finish_eating == data->philo_num)
		return (stop_sim(data), true);
	return (false);
}

static void	philo_thread_init(t_dat *data, int i)
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
		return (thread_cleanup(data, data->philo_num), false);
	while (++i < data->philo_num)
		data->philos[i].last_eaten = data->sim_start;
	start_sim(data);
	return (true);
}

int	simulate(t_dat *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->stop_lock, NULL);
	i = 0;
	while (i < data->philo_num)
	{
		philo_thread_init(data, i);
		if (pthread_create(&data->philos[i].t, NULL, philosopher, &data->philos[i]) != 0)
		{
			thread_cleanup(data, i);
			return (-1);
		}
		i++;
	}
	start_simulation(data);
	while (!simulation_done(data))
		usleep(1000);
	thread_cleanup(data, data->philo_num);
	return (0);
}
