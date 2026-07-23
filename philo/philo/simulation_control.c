/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:52:04 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/20 17:31:30 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_start(t_philo *philo)
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

void	stop_sim(t_dat *data)
{
	pthread_mutex_lock(&data->stop_lock);
	data->stop = true;
	pthread_mutex_unlock(&data->stop_lock);
}

void	start_sim(t_dat *data)
{
	pthread_mutex_lock(&data->stop_lock);
	data->start = true;
	pthread_mutex_unlock(&data->stop_lock);
}

static bool	finished_eating(t_philo *philo)
{
	return (philo->data->must_eat != -1
		&& philo->times_eaten >= philo->data->must_eat);
}

bool	simulation_done(t_dat *data)
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
			stop_sim(philo->data);
			print_death(philo);
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
			// pthread_mutex_lock(&data->stop_lock);
			// data->stop = true;
			// print_death(philo);
			// pthread_mutex_unlock(&data->stop_lock);
			// pthread_mutex_unlock(&philo->lock);
