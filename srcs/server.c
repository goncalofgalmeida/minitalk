#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h> // apagar quando já não precisar

void	handle_signal(int signum)
{
	static int	bit_index = 7;
	static char	character = 0;

	if (signum == SIGUSR1)
		character |= (1 << bit_index);
	bit_index--;
	if (bit_index < 0)
	{
		printf("%c", character);
		bit_index = 7;
		character = 0;
	}
	
}

int main(void)
{
    __pid_t pid;

    pid = getpid();
    printf("%i\n", pid); // substituir pela minha ft_printf()

	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	while
	while (1)
	{
		pause();
	}

    return (0);
}