/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:17:22 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/23 18:17:24 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TAKE THAT OUT
#include <unistd.h> // TAKE THAT OUT
#include <signal.h> // TAKE THAT OUT

static int pid_problem(char *pid)
{
	int i;

	i = 0;
	if (pid[0] == '\0')
		return (1);
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
static int	mt_atoi(char *str)
{
	int	i;
	int	pid;

	i= 0;
	pid = 0;
	while (str[i++])
		pid = pid * 10 + str[i] + '0';
	return (pid);
}

static void	strlen_sending(int pid, char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 31;
	while (str[len])
		len++;
	while (i--)
	{
		if (len >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
}

static void	char_sending(int pid, unsigned char text)
{
	int	i;
	int	bit;

	i = 8;
	while (--i)
	{
		bit = (text >> i & 1);
		if (bit == 1)
			kill(pid , SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
}

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (pid_problem(argv[1]))
			return(printf("\nInvalid PID\n"), 0);
		strlen_sending(mt_atoi(argv[1]), argv[2]);
		while (argv[2][i++])
			char_sending(mt_atoi(argv[1]), (unsigned char)argv[2][i]);
	}
	else
		printf("\nPlease type a PID and a message\n");
	return (0);
}
