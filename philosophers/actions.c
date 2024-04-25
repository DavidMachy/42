/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:19:51 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 13:56:17 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->forks[1]);
	pthread_mutex_unlock(philo->forks[0]);
}

int	fork_order(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock((philo->forks[0]));
		message(philo, "has taken a fork");
		pthread_mutex_lock((philo->forks[1]));
		message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock((philo->forks[1]));
		message(philo, "has taken a fork");
		pthread_mutex_lock((philo->forks[0]));
		message(philo, "has taken a fork");
	}
	return (0);
}

void	philo_eat(t_philo *philo)
{
	if (fork_order(philo))
		return ;
	message(philo, "is eating");
	pthread_mutex_lock(&philo->box->timing);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&philo->box->timing);
	usleep(philo->box->time_to_eat * 1000);
	drop_forks(philo);
	philo->meal_count++;
	if ((philo->meal_count == philo->box->times_must_eat
			&& philo->box->times_must_eat != -1))
	{
		pthread_mutex_lock(&philo->box->satisfaction);
		philo->box->satisfied++;
		pthread_mutex_unlock(&philo->box->satisfaction);
	}
}

void	philo_sleep(t_philo *philo)
{
	message(philo, "is sleeping");
	usleep(philo->box->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	message(philo, "is thinking");
	usleep(philo->id * 1000);
}
