/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:17:35 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/23 18:17:36 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TAKE THAT OUT
#include <unistd.h> // TAKE THAT OUT
#include <signal.h> // TAKE THAT OUT

// static void	get_str_len(int len)
// {
// 	static int	len;



// 	len = 0;
// 	if (sig == SIGUSR1)
// 		len = len * 2 + 1;
// 	else
// 		len = len * 2 + 1;
// }

static void	print_bits(int sig)
{
	static int		i;
	unsigned char	c;

	i = 7;
	c = '\0';
	if (i == 0)
	{
		i = 7;
		c = '\0';
	}
	if (i--)
	{
		if (sig == SIGUSR1)
			c = c * 2 + 1;
		else
			c = c * 2 + 0;
	}
	if (i == 0)
		write(1, &c, 1);
}

int main()
{
	int	i;
	int	len;

	i = 31;
	len = 0;
    printf("\nPID: %d\n", getpid());
	//get_str_len(len);
	while (1)
	{
		signal(SIGUSR1, print_bits);
		signal(SIGUSR2, print_bits);
		usleep(1);
	}
	return (0);
}
