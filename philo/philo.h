/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:07:08 by dstumpf           #+#    #+#             */
/*   Updated: 26/03/21 15:45:45 by dstumpf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <pthread.h>

typedef struct s_dat t_dat;

typedef	struct s_philo
{
	int			num;
	pthread_t	t;
	t_dat		*data;
	//bool		died;
	//time_t		last_eaten;
	//int			times_eaten;
}				t_philo;

struct s_dat
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	//int				stop;
	//pthread_mutex_t	stop_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
};

//utils
int	ft_atoi(const char *nptr);
int	start_simulation(t_dat *data);
//thread functions
//actions (eat/sleep/think repeat)

#endif
