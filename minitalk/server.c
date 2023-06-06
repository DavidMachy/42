/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:58:57 by dmachace          #+#    #+#             */
/*   Updated: 2023/06/06 14:21:33 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	ftload(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;

	(void)context;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = c << 1;
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	serv;

	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	bzero(&serv, sizeof(serv));
	serv.sa_sigaction = ftload;
	serv.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &serv, 0);
	sigaction(SIGUSR2, &serv, 0);
	while (1)
		pause();
	return (0);
}
