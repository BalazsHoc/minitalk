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

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	pid;

void	sig_handler(int sig)
{
	int	a;

	a = sig;
	sig = a;
}

void	send_bit(char c)
{
	static int		i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error, signal could not be sent.\n", 34);
				exit(2);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error, signal could not be sent.\n", 34);
				exit(2);
			}
		}
		pause();
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
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig_handler);
	handlear_client(argv[2]);
	handlear_client("\n");
	return (0);
}
