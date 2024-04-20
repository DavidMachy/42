/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:57:17 by marvin            #+#    #+#             */
/*   Updated: 2024/04/20 17:01:08 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	s;
	int	x;

	i = 0;
	while (ptr[i] == 32 || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	s = 1;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			s = s * -1;
		i++;
	}
	x = 0;
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		x = x * 10 + (ptr[i] - 48);
		i++;
	}
	return (x * s);
}

unsigned long	get_time(void)
{
	struct timeval	tm;
	unsigned long	time_ms;

	gettimeofday(&tm, NULL);
	time_ms = tm.tv_sec * 1000 + tm.tv_usec / 1000;
	return (time_ms);
}

void	message(t_philo *philo, char *text)
{
	pthread_mutex_lock(&philo->box->message);
	pthread_mutex_lock(&philo->box->live_laugh_love);
	if (philo->box->alive)
	{
		printf("Time:%lu Philo:%d %s\n", (get_time() - philo->box->time_init),
			philo->id, text);
	}
	pthread_mutex_unlock(&philo->box->live_laugh_love);
	pthread_mutex_unlock(&philo->box->message);
}

int	alive_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->box->timing);
	pthread_mutex_lock(&philo->box->live_laugh_love);
	if (philo->box->alive == false || (get_time()
			- philo->last_ate >= (unsigned long)philo->box->time_to_die))
	{
		pthread_mutex_unlock(&philo->box->timing);
		pthread_mutex_unlock(&philo->box->live_laugh_love);
		message(philo, "died");
		pthread_mutex_lock(&philo->box->live_laugh_love);
		philo->box->alive = false;
		pthread_mutex_unlock(&philo->box->live_laugh_love);
		return (0);
	}
	pthread_mutex_unlock(&philo->box->timing);
	pthread_mutex_unlock(&philo->box->live_laugh_love);
	return (1);
}

void	frees(t_box *box)
{
	int	i;

	i = -1;
	while (++i < box->num_of_philos)
		if (box->forks)
			pthread_mutex_destroy(&box->forks[i]);
	pthread_mutex_destroy(&box->live_laugh_love);
	pthread_mutex_destroy(&box->satisfaction);
	pthread_mutex_destroy(&box->message);
	pthread_mutex_destroy(&box->timing);
	free(box->forks);
	free(box->threads);
	free(box->philos);
	free(box);
}
