/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:58:36 by dstumpf           #+#    #+#             */
/*   Updated: 26/03/26 12:26:36 by dstumpf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>

uint64_t	get_rel_time(t_philo *philo, struct timeval *tv_old)
{
	uint64_t		diff;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		pthread_mutex_lock(&philo->data->stop_lock);
		philo->data->stop = NO_DIE;
		pthread_mutex_unlock(&philo->data->stop_lock);
		return (0);
	}
	diff = (tv.tv_sec - tv_old->tv_sec) * 1000000UL
		+ (tv.tv_usec - tv_old->tv_usec);
	return (diff / 1000);
}

bool	check_if_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_lock);
	if (philo->data->stop != -1)
	{
		pthread_mutex_unlock(&philo->data->stop_lock);
		return (true);
	}
	if (get_rel_time(philo, &philo->last_eaten) > (uint64_t)philo->data->die_time)
	{
		pthread_mutex_lock(&philo->lock);
		philo->died = true;
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_unlock(&philo->data->stop_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->stop_lock);
	return (false);
}
