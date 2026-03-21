/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:23:04 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/21 20:09:39 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

#define LEFT 0
#define RIGHT 1

static pthread_mutex_t	*get_fork(t_philo *philo, int side)
{
	int	idx;

	idx = philo->num;
	if (side == LEFT)
		return (&philo->data->forks[idx]);
	else if (philo->data->philo_num  == 1)
		return (NULL);
	else 
		return (&philo->data->forks[(idx + 1) % philo->data->philo_num]);
}

void	pickup_fork(t_philo *philo)
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	left = get_fork(philo, LEFT);
	right = get_fork(philo, RIGHT);
	if (!right)
		return ;
	pthread_mutex_lock(left);
	pthread_mutex_lock(right);
	printf("%d has taken a fork\n", philo->num + 1);
	pthread_mutex_unlock(left);
	pthread_mutex_unlock(right);
}
