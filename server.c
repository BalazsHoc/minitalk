#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	get_bit(int sig, siginfo_t	*siginfo, void *context)
{
	static int				i;
	static unsigned char	c;

	if (context)

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
	ft_printf("\nPID: %d\n", getpid());
	handler_server();
	while (1)
		pause();
	return (0);
}