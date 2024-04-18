/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:19:51 by marvin            #+#    #+#             */
/*   Updated: 2024/04/17 15:19:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->forks[1]);
	pthread_mutex_unlock(philo->forks[0]);
}

void	philo_eat(t_philo *philo)
{
    pthread_mutex_lock((philo->forks[0]));
    message(philo, "has taken a fork");
    if (!(alive_check(philo)))
        return ;
    pthread_mutex_lock((philo->forks[1]));
    message(philo, "has taken a fork");
    if (!(alive_check(philo)))
        return ;
    message(philo, "is eating");
    philo->last_ate = get_time();
    usleep(philo->box->time_to_eat * 1000);
    drop_forks(philo);
    philo->meal_count++;
}

void    philo_sleep(t_philo *philo)
{
    if (alive_check(philo))
    {
        message(philo, "is sleeping");
        usleep(philo->box->time_to_sleep * 1000);
        alive_check(philo);
    }
}

void    philo_think(t_philo *philo)
{
    if (alive_check(philo))
        message(philo, "is thinking");
}
