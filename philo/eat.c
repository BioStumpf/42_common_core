/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:23:04 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/23 17:20:23 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static void	pickup_forks(t_philo *philo, int left_fork, int right_fork)
{
	if (philo->num % 2)
	{
		pthread_mutex_lock(&philo->data->forks[left_fork]);
		printf("%d has taken a fork %d\n", philo->num + 1, left_fork + 1);
		pthread_mutex_lock(&philo->data->forks[right_fork]);
		printf("%d has taken a fork %d\n", philo->num + 1, right_fork + 1);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[right_fork]);
		printf("%d has taken a fork %d\n", philo->num + 1, right_fork + 1);
		pthread_mutex_lock(&philo->data->forks[left_fork]);
		printf("%d has taken a fork %d\n", philo->num + 1, left_fork + 1);
	}
}

static void	putdown_forks(t_philo *philo, int left_fork, int right_fork)
{
	pthread_mutex_unlock(&philo->data->forks[left_fork]);
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
}

void	eat(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->num; 
	right_fork = (left_fork + 1) % philo->data->philo_num;
	pickup_forks(philo, left_fork, right_fork);
	printf("%d is eating\n", philo->num + 1);
	putdown_forks(philo, left_fork, right_fork);
}
