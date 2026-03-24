/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:58:36 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/24 17:10:55 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>

uint64_t	get_rel_time(t_philo *philo)
{
	uint64_t		diff;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		pthread_mutex_lock(&philo->data->stop_lock);
		data->stop = 1;
		pthread_mutex_unlock(&philo->data->stop_lock);
		return (0);
	}
	diff = (tv.tv_sec - philo->last_eaten.tv_sec) * 1000000UL
		+ (tv.tv_usec - philo->last_eaten.tv_usec);
	return (diff / 1000);
}

bool	check_if_done(t_philo *philo)
{
	if (get_rel_time(philo) > philo->data->die_time)
		return (true);
	return (false);
}
