/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:58:36 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/16 15:52:16 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>

uint64_t	rel_time(struct timeval *tv_old)
{
	uint64_t		diff;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	diff = (tv.tv_sec - tv_old->tv_sec) * 1000000UL
		+ (tv.tv_usec - tv_old->tv_usec);
	return (diff / 1000);
}

bool	died(t_philo *philo)
{
	if (philo->died)
		return (true);
	if (rel_time(&philo->last_eaten) > (uint64_t)philo->data->die_time)
		philo->died = true;
	return (philo->died);
}
