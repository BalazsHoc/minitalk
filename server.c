#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	get_bit(int sig)
{
	static int				i;
	static unsigned char	c;


	if (!i)
		i = 8;
	if (i)
	{
		if (sig == SIGUSR1)
			c = c * 2 + 1;
		else if (sig == SIGUSR2)
			c = c * 2 + 0;
		if (i == 1)
			write(1, &c, 1);
		i--;
	}
}

int	main()
{
	//struct sigaction	sa; // I can get the senders pid
	ft_printf("\nPID: %d\n", getpid());
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1)
		pause();
	return (0);
}