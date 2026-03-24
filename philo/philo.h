/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:07:08 by dstumpf           #+#    #+#             */
/*   Updated: 2026/03/24 16:52:20 by dstumpf          ###   ########.fr       */
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
	pthread_t		t;
	t_dat			*data;
	bool			done;
	struct timeval	last_eaten;
//	uint64_t	last_eaten;
	//int			times_eaten;
}				t_philo;

struct s_dat
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				stop;
//	struct timeval	sim_start;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
};

//utils
int			ft_atoi(const char *nptr);
//actions (eat/sleep/think repeat)
void		ph_eat(t_philo *philo);
void		ph_sleep(t_philo *philo);
void		ph_think(t_philo *philo);
int			init_time(t_dat *data);
uint64_t	get_time_since_start(t_dat *data);
//simulation
int			simulate(t_dat *data);

#endif
