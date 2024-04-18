/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:52:29 by marvin            #+#    #+#             */
/*   Updated: 2024/02/24 16:52:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void    loner(t_philo philo)
{
	philo->forks[0] = &box->forks[philo->which - 1];
    pthread_mutex_lock((philo->forks[0]));
    message(philo, "has taken a fork");
	usleep(box->time_to_die * 1000);
    alive_check(philo);
}*/

void    *routine(void *philo_arg)
{
    t_philo *philo;
    t_box   *box;

    if (!philo_arg)
        return (NULL);
    philo = (t_philo *) philo_arg;
    box = philo->box;
    if (box->num_of_philos == 1)
        return (/*loner(philo), */NULL);
	philo->forks[0] = &box->forks[philo->which % box->num_of_philos];
	philo->forks[1] = &box->forks[philo->which - 1];
    while(box->alive == true)
    {
        if (philo->id % 2 == 0 && philo->meal_count == 0)
			usleep(box->time_to_eat * 1000);
        philo_eat(philo);
        philo_sleep(philo);
        philo_think(philo);
    }
    return (NULL);
}

int main(int ac, char **av)
{
    t_box   *box;
    t_philo *philo;
    int     i;

    if (arg_check(ac, av))
        box = init(ac, av);
    i = -1;
    while(++i < box->num_philos)
    {
        philo = init_philo(i + 1, box);
        pthread_create(&(box->philo_threads[i]), NULL, routine, (void *)philo);
    }
    i = -1;
    while(++i < box->num_philos)
        pthread_join((box->philo_threads[i]), NULL);
    return (0);
}