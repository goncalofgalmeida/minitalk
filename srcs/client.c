#include "../libft/libft.h"

#include <unistd.h>
#include <signal.h>
#include <stdio.h> // apagar quando já não precisar
#include <stdlib.h>

void	process_and_send_bit(int server_pid, int bit)
{
	if (bit)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	send_message_length(int server_pid, int len)
{
	int i;
	int	bit;

	i = 31;
	while (i >= 0)
	{
		bit = (len >> i) & 1;
		process_and_send_bit(server_pid, bit);
		usleep(100); // CHECK IF NEEDED
		i--;
	}
}

void	send_stop_char(int server_pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ('\0' >> i) & 1;
		process_and_send_bit(server_pid, bit);
		usleep(100);
		i--;
	}
}

void	send_message(int server_pid, char *msg)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (msg[i])
	{
		j = 7;
		while (j >= 0)
		{
			bit = (msg[i] >> j) & 1;
			process_and_send_bit(server_pid, bit);
			usleep(100); // CHECK IF NEEDED
			j--;
		}
		i++;
	}
	send_stop_char(server_pid);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*msg;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		msg = argv[2];
		send_message_length(server_pid, ft_strlen(msg));
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
