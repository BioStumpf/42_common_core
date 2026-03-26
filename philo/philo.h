/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:07:08 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/26 17:40:58 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdint.h>

typedef struct s_dat t_dat;

typedef	struct s_philo
{
	int				num;
	int				times_eaten;
	struct timeval	last_eaten;
	t_dat			*data;
	pthread_mutex_t	lock;
	pthread_t		t;
}					t_philo;

struct s_dat
{
	bool			stop;
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	struct timeval	sim_start;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
};

//utils
int			ft_atoi(const char *nptr);
//actions (eat/sleep/think repeat)
bool		ph_eat(t_philo *philo);
bool		ph_sleep(t_philo *philo);
bool		ph_think(t_philo *philo);
int			init_time(t_dat *data);
uint64_t	get_rel_time(struct timeval *);
bool		check_if_done(t_philo *philo);
bool		check_if_died(t_philo *philo);
//simulation
int			simulate(t_dat *data);

#endif
