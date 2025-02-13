#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h> // apagar quando já não precisar

void sig_handle_exit(int signum)
{
	printf("\nRecieved signal: %i\n", signum);
	exit(0);
}

int main(void)
{
    __pid_t pid;

    pid = getpid();
    printf("%i\n", pid); // substituir pela minha ft_printf()

	signal(SIGINT, sig_handle_exit);
	signal(SIGTERM, sig_handle_exit);	
	while (1)
	{
		
	}

    return (0);
}

struct sigaction action;