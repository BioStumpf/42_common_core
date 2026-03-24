/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:23:04 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/24 15:01:41 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static void	pickup_forks(t_philo *philo, int left_fork, int right_fork)
{
	if (philo->num % 2)
	{
		pthread_mutex_lock(&philo->data->forks[left_fork]);
		printf("%lu %d has taken a fork\n", get_time_since_start(philo->data),  philo->num + 1);
		//printf("%d has taken a fork %d\n", philo->num + 1, left_fork + 1);
		pthread_mutex_lock(&philo->data->forks[right_fork]);
		printf("%lu %d has taken a fork\n", get_time_since_start(philo->data),  philo->num + 1);
		//printf("%d has taken a fork %d\n", philo->num + 1, right_fork + 1);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[right_fork]);
		printf("%lu %d has taken a fork\n", get_time_since_start(philo->data),  philo->num + 1);
		//printf("%d has taken a fork %d\n", philo->num + 1, right_fork + 1);
		pthread_mutex_lock(&philo->data->forks[left_fork]);
		printf("%lu %d has taken a fork\n", get_time_since_start(philo->data),  philo->num + 1);
		//printf("%d has taken a fork %d\n", philo->num + 1, left_fork + 1);
	}
}

static void	putdown_forks(t_philo *philo, int left_fork, int right_fork)
{
	pthread_mutex_unlock(&philo->data->forks[left_fork]);
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
}

void	ph_eat(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->num; 
	right_fork = (left_fork + 1) % philo->data->philo_num;
	pickup_forks(philo, left_fork, right_fork);
	printf("%lu %d is eating\n", get_time_since_start(philo->data),  philo->num + 1);
	usleep(philo->data->eat_time);
	putdown_forks(philo, left_fork, right_fork);
}
