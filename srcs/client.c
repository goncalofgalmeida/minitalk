/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:45:35 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/05 20:54:31 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <signal.h>
#include <unistd.h>

int	str_is_pid(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

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

void	send_stop_char(int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		process_and_send_bit(server_pid, '\0', i);
		i++;
		usleep(300);
	}
}

void	send_message(int server_pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			process_and_send_bit(server_pid, msg[i], j);
			j++;
			usleep(300);
		}
		i++;
		//pause();
	}
	send_stop_char(server_pid);
}

void	send_length(int server_pid, int length)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		process_and_send_len_bit(server_pid, length, i);
		usleep(300);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*msg;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		msg = argv[2];
		send_length(server_pid, ft_strlen(msg));
		usleep(500);
		send_message(server_pid, msg);
		return (0);
	}
	ft_putstr_fd("Number of parameters is not two, terminating...\n", 2);
	return (1);
}
