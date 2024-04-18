/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:52:29 by marvin            #+#    #+#             */
/*   Updated: 2024/04/18 18:39:07 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loner(t_philo *philo)
{
	t_box	*box;

	box = philo->box;
	philo->forks[0] = &box->forks[philo->id - 1];
	pthread_mutex_lock((philo->forks[0]));
	message(philo, "has taken a fork");
	usleep(box->time_to_die * 1000);
	message(philo, "died");
	philo->box->alive = false;
	pthread_mutex_unlock(philo->forks[0]);
	return ;
}

void	*life_checker_boi(void *box_arg)
{
	t_box	*box;
	int		i;

	if (!box_arg)
		return (NULL);
	box = (t_box *)box_arg;
	while (1)
	{
		i = -1;
		while(++i < box->num_of_philos)
			alive_check(&box->philos[i]);
		if (!(box->alive))
			break ;
		usleep(1000);
	}
	return (NULL);
}

void	*routine(void *philo_arg)
{
	t_box	*box;
	t_philo	*philo;

	if (!philo_arg)
		return (NULL);
	philo = (t_philo *)philo_arg;
	box = philo->box;
	if (box->num_of_philos == 1)
		return (loner(philo), NULL);
	philo->forks[0] = &box->forks[philo->id % box->num_of_philos];
	philo->forks[1] = &box->forks[philo->id - 1];
	while (box->alive == true)
	{
		if (philo->id % 2 == 1 && philo->meal_count == 0)
			usleep(60 * 1000);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_box	*box;
	t_philo	*philo;
	int		i;

	if (arg_check(ac, av))
		box = init(ac, av);
	else
		return (0);
	box->alive = true;
	box->satisfied = 0;
	box->time_init = get_time();
	i = -1;
	while (++i < box->num_of_philos)
	{
		philo = init_philo(i + 1, box);
		pthread_create(&(box->threads[i]), NULL, routine, (void *)philo);
	}
	if (box->num_of_philos > 1)
		pthread_create(&(box->life_checker), NULL, life_checker_boi, (void *)box);
	i = -1;
	while (++i < box->num_of_philos)
		pthread_join((box->threads[i]), NULL);
	pthread_join((box->life_checker), NULL);
	frees(box);
	return (0);
}
