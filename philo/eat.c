/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:23:04 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/16 16:01:25 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

		//printf("%d has taken a fork %d\n", philo->num + 1, left_fork + 1);
		//printf("%d has taken a fork %d\n", philo->num + 1, right_fork + 1);

static void	putdown_forks(t_philo *philo, int left_fork, int right_fork)
{
	pthread_mutex_unlock(&philo->data->forks[left_fork]);
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
}

static bool	pickup_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&philo->data->forks[fork]);
	pthread_mutex_lock(&philo->data->stop_lock);
	pthread_mutex_lock(&philo->lock);
	if (philo->data->stop || died(philo))
	{
		pthread_mutex_unlock(&philo->data->stop_lock);
		pthread_mutex_unlock(&philo->lock);
		return (false);
	}
	printf("%lu %d has taken a fork\n", get_rel_time(&philo->data->sim_start),  philo->num + 1);
	pthread_mutex_unlock(&philo->data->stop_lock);
	pthread_mutex_unlock(&philo->lock);
	return (true);
}

static bool	lock_forks_ordered(t_philo *philo, int first, int second)
{
	if (!pickup_fork(philo, first))
	{
		pthread_mutex_unlock(&philo->data->forks[first]);
		return (false);
	}
	if (!pickup_fork(philo, second))
	{
		pthread_mutex_unlock(&philo->data->forks[first]);
		pthread_mutex_unlock(&philo->data->forks[second]);
		return (false);
	}
	return (true);
}

static bool	pickup_forks(t_philo *philo, int left_fork, int right_fork)
{
	if (philo->num % 2 && lock_forks_ordered(philo, left_fork, right_fork))
		return (true);
	else if (lock_forks_ordered(philo, right_fork, left_fork))
		return (true);
	return (false);
}

bool	ph_eat(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->num; 
	right_fork = (left_fork + 1) % philo->data->philo_num;
	if (!pickup_forks(philo, left_fork, right_fork))
		return (false);
	pthread_mutex_lock(&philo->lock);
	pthread_mutex_lock(&philo->data->stop_lock);
	if (philo->data->stop || died(philo))
	{
		putdown_forks(philo, left_fork, right_fork);
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_unlock(&philo->data->stop_lock);
		return (false);
	}
	printf("%lu %d is eating\n", get_rel_time(&philo->data->sim_start),  philo->num + 1);
	gettimeofday(&philo->last_eaten, NULL);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(&philo->data->stop_lock);
	usleep(philo->data->eat_time);
	putdown_forks(philo, left_fork, right_fork);
	return (true);
}
