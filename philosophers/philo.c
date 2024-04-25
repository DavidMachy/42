/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:52:29 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 13:49:25 by dmachace         ###   ########.fr       */
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

void	ate_enough_check(t_box *box)
{
	pthread_mutex_lock(&box->satisfaction);
	if (box->satisfied == box->num_of_philos)
	{
		pthread_mutex_unlock(&box->satisfaction);
		pthread_mutex_lock(&box->live_laugh_love);
		box->alive = false;
		pthread_mutex_unlock(&box->live_laugh_love);
		return ;
	}
	pthread_mutex_unlock(&box->satisfaction);
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
		while (++i < box->num_of_philos)
			alive_check(&box->philos[i]);
		ate_enough_check(box);
		pthread_mutex_lock(&box->live_laugh_love);
		if (!(box->alive))
		{
			pthread_mutex_unlock(&box->live_laugh_love);
			break ;
		}
		pthread_mutex_unlock(&box->live_laugh_love);
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
	pthread_mutex_lock(&philo->box->live_laugh_love);
	while (box->alive == true)
	{
		pthread_mutex_unlock(&philo->box->live_laugh_love);
		if (philo->id % 2 == 1 && philo->meal_count == 0)
			usleep(60 * 1000);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		pthread_mutex_lock(&philo->box->live_laugh_love);
	}
	pthread_mutex_unlock(&philo->box->live_laugh_love);
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
	box->time_init = get_time();
	i = -1;
	while (++i < box->num_of_philos)
	{
		philo = init_philo(i + 1, box);
		pthread_create(&(box->threads[i]), NULL, routine, (void *)philo);
	}
	if (box->num_of_philos > 1)
		pthread_create(&(box->life_checker), NULL, life_checker_boi,
			(void *)box);
	i = -1;
	while (++i < box->num_of_philos)
		pthread_join((box->threads[i]), NULL);
	if (box->num_of_philos > 1)
		pthread_join((box->life_checker), NULL);
	return (frees(box), 0);
}
