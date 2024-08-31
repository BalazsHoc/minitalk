/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:11:17 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/31 12:11:23 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

data	*server_data;

void	get_bit(int sig, siginfo_t	*siginfo, void *context)
{
	static int				i;
	static unsigned char	c;

	(void)context;
	if (!i)
		i = 8;
	if (i)
	{
		if (sig == SIGUSR1)
		{
			ft_printf("1");
			c = c * 2 + 1;
		}
		else if (sig == SIGUSR2)
		{
			ft_printf("0");
			c = c * 2 + 0;
		}
		i--;
		if (i == 0)
		{
			write(1, &c, 1);
			ft_printf("\n");
			c = 0;
		}
		kill(siginfo->si_pid, SIGUSR1);
	}
}

void	handler_server()
{
	struct sigaction	sa;

	sa.sa_sigaction = get_bit;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main()
{
	server_data = malloc(sizeof(data));
	if (!server_data)
		return (write(2, "Memory allocation error\n", 25), 1);
	// server_data->message = malloc(sizeof(char) * 1024);
	// if (!server_data->message)
	// 	return (write(2, "Memory allocation error\n", 25), 2);
	ft_printf("PID: %d\n", getpid());
	handler_server();
	while (1)
		pause();
	return (0);
}
