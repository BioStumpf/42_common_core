/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:42:25 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/20 14:47:33 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ph_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	pthread_mutex_lock(&philo->data->stop_lock);
	if (philo->data->stop || died(philo))
	{
		pthread_mutex_unlock(&philo->data->stop_lock);
		pthread_mutex_unlock(&philo->lock);
		return (false);
	}
	pthread_mutex_unlock(&philo->lock);
	print_sleep(philo);
	pthread_mutex_unlock(&philo->data->stop_lock);
	usleep(philo->data->sleep_time);
	return (true);
}

bool	ph_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	pthread_mutex_lock(&philo->data->stop_lock);
	if (philo->data->stop || died(philo))
	{
		pthread_mutex_unlock(&philo->data->stop_lock);
		pthread_mutex_unlock(&philo->lock);
		return (false);
	}
	pthread_mutex_unlock(&philo->lock);
	print_think(philo);
	pthread_mutex_unlock(&philo->data->stop_lock);
	usleep(philo->data->think_time);
	return (true);
}
