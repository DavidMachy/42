/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:59:03 by dmachace          #+#    #+#             */
/*   Updated: 2023/06/06 14:49:40 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

static int	g_rec;

static void	sig_handler(int sig)
{
	static int	i;

	if (sig == SIGUSR2)
		i++;
	else if (sig == SIGUSR1)
	{
		ft_putstr_fd("Server received ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(" bits\n", 1);
	}
	g_rec = 1;
}

static void	send(pid_t pid, char *s)
{
	int		i;
	int		j;
	char	c;

	while (*s)
	{
		i = 8;
		c = *s++;
		while (i--)
		{
			j = 0;
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_rec == 0)
			{
				if (j == 5000)
				{
					ft_putstr_fd("No response from a server\n", 1);
					return ;
				}
				j++;
				usleep(1);
			}
			g_rec = 0;
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*msg;
	struct sigaction	clnt;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong number of arguments", 1);
		return (0);
	}
	bzero(&clnt, sizeof(clnt));
	clnt.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &clnt, 0);
	sigaction(SIGUSR2, &clnt, 0);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	send(pid, msg);
	return (0);
}
