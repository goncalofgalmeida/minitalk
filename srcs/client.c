#include "../libft/libft.h"

#include <unistd.h>
#include <signal.h>
#include <stdio.h> // apagar quando já não precisar
#include <stdlib.h>

void	send_message(int server_pid, char *msg)
{
	int i;
	int j;

	i = 0;
	while (msg[i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((msg[i] >> j) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j--;
			usleep(100); // CHECK IF NEEDED
		}
		i++;
	}
	j = 7;
	while (j >= 0)
	{
		if (('\0' >> j) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		j--;
		usleep(100); // CHECK IF NEEDED
	}
}

int main(int argc, char **argv)
{
    int server_pid;
    char *msg;

    if (argc == 3)
    {
        server_pid = ft_atoi(argv[1]);
        msg = argv[2];

		send_message(server_pid, msg);
		/* while (1)
		{
			
		} */
        return (0);
    }
    else
    {
        printf("Number of parameters is not two, terminating..."); // substituir pela minha ft_printf()
        return (1);
    }
}