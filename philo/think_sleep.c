/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:42:25 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/16 18:00:55 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

bool	ph_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_lock);
	pthread_mutex_lock(&philo->lock);
	if (philo->data->stop || died(philo))
	{
		pthread_mutex_unlock(&philo->data->stop_lock);
		pthread_mutex_unlock(&philo->lock);
		return (false);
	}
	printf("%lu %d is sleeping\n", get_rel_time(&philo->data->sim_start),  philo->num + 1);
	pthread_mutex_unlock(&philo->data->stop_lock);
	pthread_mutex_unlock(&philo->lock);
	usleep(philo->data->sleep_time);
	return (true);
}

bool	ph_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_lock);
	pthread_mutex_lock(&philo->lock);
	if (philo->data->stop || died(philo))
	{
		pthread_mutex_unlock(&philo->data->stop_lock);
		pthread_mutex_unlock(&philo->lock);
		return (false);
	}
	printf("%lu %d is thinking\n", get_rel_time(&philo->data->sim_start),  philo->num + 1);
	pthread_mutex_unlock(&philo->data->stop_lock);
	pthread_mutex_unlock(&philo->lock);
	usleep(philo->data->think_time);
	return (true);
}
