/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:31:03 by marvin            #+#    #+#             */
/*   Updated: 2024/04/20 16:36:48 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_check(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (printf("Wrong number of args\n"), 0);
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| ft_atoi(av[4]) < 0)
		return (printf("Invalid args\n"), 0);
	if (ac == 6 && ft_atoi(av[5]) < 0)
		return (printf("Invalid optional arg\n"), 0);
	return (1);
}

void	init_mutexes(t_box *box)
{
	pthread_mutex_init(&box->live_laugh_love, NULL);
	pthread_mutex_init(&box->satisfaction, NULL);
	pthread_mutex_init(&box->message, NULL);
	pthread_mutex_init(&box->timing, NULL);
}

t_philo	*init_philo(int id, t_box *box)
{
	t_philo	*philo;

	philo = &box->philos[id - 1];
	philo->id = id;
	philo->box = box;
	philo->meal_count = 0;
	philo->last_ate = get_time();
	return (philo);
}

t_box	*init(int ac, char **av)
{
	t_box	*box;
	int		i;

	box = malloc(sizeof(t_box));
	if (!box)
		return (NULL);
	box->num_of_philos = ft_atoi(av[1]);
	box->philos = malloc(sizeof(t_philo) * box->num_of_philos);
	box->forks = malloc(sizeof(pthread_mutex_t) * box->num_of_philos);
	box->threads = malloc(sizeof(pthread_t) * box->num_of_philos);
	if (!box->philos || !box->forks || !box->threads)
		return (frees(box), NULL);
	init_mutexes(box);
	i = -1;
	while (++i < box->num_of_philos)
		pthread_mutex_init(&box->forks[i], NULL);
	box->alive = true;
	box->time_to_die = ft_atoi(av[2]);
	box->time_to_eat = ft_atoi(av[3]);
	box->time_to_sleep = ft_atoi(av[4]);
	box->times_must_eat = -1;
	box->satisfied = 0;
	if (ac == 6)
		box->times_must_eat = ft_atoi(av[5]);
	return (box);
}
