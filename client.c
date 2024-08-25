#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	*send_bit(int pid, char *str)
{
	void	*d;
	int		i;
	int		j;
	char	c;

	d = 0;
	j = 0;
	while (str[j])
	{
		i = 8;
		c = str[j];
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(42);
		}
		j++;
	}
	return (void *)(d);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_bit(atoi(argv[1]), argv[2]);
	}
 	return (0);
}