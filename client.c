/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:11:05 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/31 12:11:08 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_client	*g_client;

int	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_client->got_signal = 1;
	return (g_client->got_signal);
}

void	send_bit(char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(g_client->server_pid, SIGUSR1) == -1)
			{
				write(2, "Error, signal could not be sent.\n", 34);
				free(g_client);
				exit(3);
			}
		}
		else
		{
			if (kill(g_client->server_pid, SIGUSR2) == -1)
			{
				write(2, "Error, signal could not be sent.\n", 34);
				free(g_client);
				exit(3);
			}
		}
		while (!g_client->got_signal)
			pause();
		g_client->got_signal = 0;
		i--;
	}
}

void	handlear_client(char *str)
{
	while (*str)
	{
		send_bit(*str);
		str++;
	}
	send_bit('\0');
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Please type a PID and a message!\n");
		exit(1);
	}
	while (ft_isdigit(argv[1][i]))
		i++;
	if (argv[1][i] && !ft_isdigit(argv[1][i]))
		exit(ft_printf("Invalid PID\n"));
	g_client = malloc(sizeof(t_client));
	if (!g_client)
		return (write(2, "Error, memory allocation\n", 25), 2);
	g_client->server_pid = ft_atoi(argv[1]);
	g_client->got_signal = 0;
	signal(SIGUSR1, (void *)sig_handler);
	handlear_client(argv[2]);
	return (free(g_client), 0);
}
