/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:57:31 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 13:36:39 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_box
{
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	live_laugh_love;
	pthread_mutex_t	satisfaction;
	pthread_mutex_t	message;
	pthread_mutex_t	timing;
	pthread_t		*threads;
	pthread_t		life_checker;
	bool			alive;
	unsigned long	time_init;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				satisfied;
}					t_box;

typedef struct s_philo
{
	int				id;
	int				meal_count;
	unsigned long	last_ate;
	unsigned long	time_slept;
	pthread_mutex_t	*forks[2];
	t_box			*box;
}					t_philo;

/* Main */
void				loner(t_philo *philo);
void				ate_enough_check(t_box *box);
void				*life_checker_boi(void *box_arg);
void				*routine(void *philo_arg);

/* Init */
int					arg_check(int ac, char **av);
void				init_mutexes(t_box *box);
t_philo				*init_philo(int id, t_box *box);
t_box				*init(int ac, char **av);

/* Actions */
void				drop_forks(t_philo *philo);
int					fork_order(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo);

/* Utils */
int					ft_atoi(const char *ptr);
unsigned long		get_time(void);
void				message(t_philo *philo, char *text);
int					alive_check(t_philo *philo);
void				frees(t_box *box);

#endif