/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:42:25 by dstumpf           #+#    #+#             */
/*   Updated: 26/03/25 11:14:49 by dstumpf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	ph_sleep(t_philo *philo)
{
	printf("%lu %d is sleeping\n", get_rel_time(philo, &philo->data->sim_start),  philo->num + 1);
	usleep(philo->data->sleep_time);
}

void	ph_think(t_philo *philo)
{
	printf("%lu %d is thinking\n", get_rel_time(philo, &philo->data->sim_start),  philo->num + 1);
}
