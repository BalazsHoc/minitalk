#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	f()
{
	printf("Hell yeah\n");
}

int	main()
{
	printf("PID: %d\n", getpid());
	signal(SIGUSR1, f);
	while (1)
		pause();
}