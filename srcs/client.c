/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:45:35 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/06 15:08:16 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <signal.h>
#include <unistd.h>

void	process_and_send_len_bit(int server_pid, unsigned int value, int index)
{
	if ((value >> index) & 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	process_and_send_bit(int server_pid, char character, int index)
{
	if ((character >> index) & 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	handle_signal(int signum)
{
	if (signum == SIGUSR1)
		return ;
	else
		exit(0);
}

void	send_byte(int server_pid, char character)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		process_and_send_bit(server_pid, character, i);
		i++;
		// usleep(300); // delete
	}
}

void	send_message(int server_pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte(server_pid, msg[i]);
		i++;
		//pause();
	}
	send_byte(server_pid, '\0');
}

void	send_length(int server_pid, int length)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		process_and_send_len_bit(server_pid, length, i);
		usleep(300); //delete
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*msg;
	struct sigaction	sa;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		msg = argv[2];
		sigemptyset(&sa.sa_mask);
		sa.sa_handler = handle_signal;
		sa.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_length(server_pid, ft_strlen(msg));
		// usleep(500); // delete
		send_message(server_pid, msg);
		while (1)
		{
			pause();
		}
		
		return (0);
	}
	ft_putstr_fd("Number of parameters is not two, terminating...\n", 2);
	return (1);
}
