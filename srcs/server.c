/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:45:39 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/06 15:06:34 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <stdio.h> // delete

void	reset_variables(t_server_state *server, int *current_char_index)
{
	server->len_recieved = 0;
	server->client_status = 0;
	server->current_bits = 0;
	server->bit_index = 0;
	server->msg_length = 0;
	server->character = 0;
	server->message = NULL;
	server->client_pid = 0;
	*current_char_index = 0;
}

void	check_client_status(int client_pid, t_server_state *server)
{
	// check if client still exists, if not reset server.client_status variable
	if (kill(client_pid, 0) == -1)
	{
		(void)server; // delete
		ft_putstr_fd("Client process terminated.\n", 1);
		// reset_variables(server, int *current_char_index); // check if correct
	}
}

void	append_char_to_msg(char character, char *msg, int *index)
{
	msg[*index] = character;
	(*index)++;
}

void	handle_char(t_server_state *server, char character, char *msg_ptr, int *msg_index)
{
	if (character == '\0')
	{
		append_char_to_msg(character, msg_ptr, msg_index); // should I do this after calloc?
		ft_putstr_fd(msg_ptr, 1);
		ft_putchar_fd('\n', 1);
		free(msg_ptr);
		reset_variables(server, msg_index);
		kill(server->client_pid, SIGUSR2);
	}
	else
	{
		append_char_to_msg(character, msg_ptr, msg_index);
		kill(server->client_pid, SIGUSR1);
	}
	server->character = 0;
	server->current_bits = 0;
}

void	check_len_status(t_server_state *server)
{
	if (server->current_bits == sizeof(int) * 8) // 32
	{
		server->len_recieved = 1;
		server->current_bits = 0;
		ft_putstr_fd("Message length: ", 1); // delete
		ft_putnbr_fd(server->msg_length, 1); // delete
		ft_putchar_fd('\n', 1);
		server->message = ft_calloc(server->msg_length + 1, sizeof(char));
		if (!server->message)
			exit(1); // TO DO allocation failed, print error, handle error and terminate 
	}
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static t_server_state	server;
	static int				current_char_index;
	// should I make the server.character just a static char variable here?

	(void)context;
	if (server.client_pid && server.client_pid != info->si_pid)
		return;
	if (!server.client_pid)
		server.client_pid = info->si_pid;
	//check_client_status(info->si_pid, &server);
	if (!server.len_recieved)
	{
		if (signum == SIGUSR1)
			server.msg_length |= (1 << server.current_bits);
		server.current_bits++;
		check_len_status(&server);
	}
	else // already recieving message
	{
		if (signum == SIGUSR1)
			server.character |= (1 << server.current_bits);
		server.current_bits++;
		if (server.current_bits == 8)
		{
			handle_char(&server, server.character, server.message, &current_char_index);
		}
	}
}

void	print_server_pid(void)
{
	__pid_t	pid;

	pid = getpid();
	ft_putstr_fd("Server's PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	print_server_pid();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
