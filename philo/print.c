/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:42:11 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/20 14:46:57 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_death(t_philo *philo)
{
	printf("%lu %d died\n", rel_time(&philo->data->sim_start), philo->num + 1);
}

void	print_fork(t_philo *philo)
{
	printf("%lu %d has taken a fork\n", rel_time(&philo->data->sim_start),
		philo->num + 1);
}

void	print_eat(t_philo *philo)
{
	printf("%lu %d is eating\n", rel_time(&philo->data->sim_start),
		philo->num + 1);
}

void	print_sleep(t_philo *philo)
{
	printf("%lu %d is sleeping\n", rel_time(&philo->data->sim_start),
		philo->num + 1);
}

void	print_think(t_philo *philo)
{
	printf("%lu %d is thinking\n", rel_time(&philo->data->sim_start),
		philo->num + 1);
}
