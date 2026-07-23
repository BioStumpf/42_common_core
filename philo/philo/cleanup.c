/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:50:35 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/20 14:09:58 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mutex_cleanup(t_dat *data, int mutexes)
{
	int	i;

	i = 0;
	while (i < mutexes)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->stop_lock);
}

static void	thread_cleanup(t_dat *data, int philos)
{
	int	i;

	i = 0;
	while (i < philos)
		pthread_join(data->philos[i++].t, NULL);
}

void	sim_cleanup(t_dat *data, int philos, int mutexes)
{
	int	i;

	i = 0;
	stop_sim(data);
	start_sim(data);
	thread_cleanup(data, philos);
	mutex_cleanup(data, mutexes);
}
