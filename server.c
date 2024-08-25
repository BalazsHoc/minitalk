#include <stdio.h>
#include <unistd.h>
#include <signal.h>

unsigned char	c;

void	get_bit(int sig)
{
	static int		i;

	i = 7;
	if (!i)
	{
		write(1, &c, 1);
		write(1, "\n", 1);
		i = 8;
	}
	if (i--)
	{
		printf("I got signal: ");
		if (sig == SIGUSR1)
		{
			printf("1\n");
			c = c * 2 + 1;
		}
		else if (sig == SIGUSR2)
		{
			printf("0\n");
			c = c * 2 + 0;
		}
		else
			return ;
	}
}

int	main()
{
	printf("\nPID: %d\n", getpid());
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1)
		pause();
}