#include "../libft/libft.h"

#include <unistd.h>
#include <signal.h>
#include <stdio.h> // apagar quando já não precisar
#include <stdlib.h>

void	process_and_send_bit(int server_pid, char character, int index)
{
	if ((character >> index) & 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	send_stop_char(int server_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		process_and_send_bit(server_pid, '\0', i);
		i--;
		usleep(300);
	}
}

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
			process_and_send_bit(server_pid, msg[i], j);
			j--;
			usleep(300);
		}
		i++;
	}
	send_stop_char(server_pid);
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
        return (0);
    }
    else
    {
        printf("Number of parameters is not two, terminating..."); // substituir pela minha ft_printf()
        return (1);
    }
}