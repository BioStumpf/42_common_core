/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:07:08 by dstumpf           #+#    #+#             */
/*   Updated: 2026/07/22 14:45:08 by dstumpf          ###   ########.fr       */
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

typedef struct s_dat	t_dat;

typedef struct s_philo
{
	bool			died;
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
	bool			start;
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				think_time;
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
uint64_t	rel_time(struct timeval *tv_old);
bool		died(t_philo *philo);
//simulation
void		*phil(void *input);
bool		simulation_done(t_dat *data);
void		start_sim(t_dat *data);
void		stop_sim(t_dat *data);
int			simulate(t_dat *data);
void		wait_for_start(t_philo *philo);
//cleanup
void		sim_cleanup(t_dat *data, int philos, int mutexes);
//printing
void		print_death(t_philo *philo);
void		print_think(t_philo *philo);
void		print_sleep(t_philo *philo);
void		print_eat(t_philo *philo);
void		print_fork(t_philo *philo);

#endif
