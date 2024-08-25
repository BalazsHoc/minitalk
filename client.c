#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	*f(int pid)
{
	void	*d;

	d = 0;
	kill(pid, SIGUSR1);
	return (void *)(d);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		signal(SIGUSR1, f(atoi(argv[1])));
 	return (0);
}