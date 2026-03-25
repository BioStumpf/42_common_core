/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:23:04 by dstumpf           #+#    #+#             */
/*   Updated: 26/03/25 12:03:10 by dstumpf            ###   ########.fr       */
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

static bool	lock_forks_ordered(t_philo *philo, int first, int second)
{
	pthread_mutex_lock(&philo->data->forks[first]);
	if (check_if_done(philo))
	{
		pthread_mutex_unlock(&philo->data->forks[first]);
		return (false);
	}
	printf("%lu %d has taken a fork\n", get_rel_time(philo, &philo->data->sim_start),  philo->num + 1);
	pthread_mutex_lock(&philo->data->forks[second]);
	if (check_if_done(philo))
	{
		putdown_forks(philo, first, second);
		return (false);
	}
	printf("%lu %d has taken a fork\n", get_rel_time(philo, &philo->data->sim_start),  philo->num + 1);
	return (true);
}

static bool	pickup_forks(t_philo *philo, int left_fork, int right_fork)
{
	if (philo->num % 2)
		lock_forks_ordered(philo, left_fork, right_fork);
	else
		lock_forks_ordered(philo, right_fork, left_fork);
	return (true);
}

bool	ph_eat(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->num; 
	right_fork = (left_fork + 1) % philo->data->philo_num;
	if (!pickup_forks(philo, left_fork, right_fork))
		return (false);
	if (check_if_done(philo))
	{
		putdown_forks(philo, left_fork, right_fork);
		return (false);
	}
	printf("%lu %d is eating\n", get_rel_time(philo, &philo->data->sim_start),  philo->num + 1);
	if (gettimeofday(&philo->last_eaten, NULL) != 0)
		return (false);
	philo->times_eaten++;
	usleep(philo->data->eat_time);
	putdown_forks(philo, left_fork, right_fork);
	return (true);
}
