/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_threads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:52:04 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/20 17:10:52 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*one_phil(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->num]);
	print_fork(philo);
	usleep(philo->data->die_time);
	pthread_mutex_lock(&philo->lock);
	died(philo);
	pthread_mutex_unlock(&philo->data->forks[philo->num]);
	pthread_mutex_unlock(&philo->lock);
	return (NULL);
}

void	*phil(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	wait_for_start(philo);
	if (philo->data->philo_num == 1)
		return (one_phil(philo));
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
