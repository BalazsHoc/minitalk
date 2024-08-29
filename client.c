#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	pid;

void sig_handler(int sig)
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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		i--;
	}
}

void handlear_client(char *str)
{
	while (*str)
	{
		send_bit(*str);
		str++;
	}
}

int main(int argc, char **argv)
{

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig_handler);
	handlear_client(argv[2]);
 	return (0);
}