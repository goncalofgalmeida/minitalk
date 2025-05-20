/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:45:39 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/20 15:42:20 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	append_char_to_msg(char c, char **msg_ptr)
{
	char	*c_to_str;
	char	*temp;

	c_to_str = (char *)malloc(2 * sizeof(char));
	if (!c_to_str)
		exit(1);
	c_to_str[0] = c;
	c_to_str[1] = '\0';
	if (*msg_ptr == NULL)
		*msg_ptr = ft_strdup(c_to_str);
	else
	{
		temp = *msg_ptr;
		*msg_ptr = ft_strjoin(temp, c_to_str);
		free(temp);
	}
	free(c_to_str);
}

void	handle_complete_msg(char character, char **message, int *bit_index)
{
	if (character == '\0')
	{
		ft_putstr_fd(*message, 1);
		ft_putchar_fd('\n', 1);
		free(*message);
		*message = NULL;
	}
	else
		append_char_to_msg(character, message);
	*bit_index = 7;
}

void	perform_sig_processing(int signum, int *flag)
{
	static int	bit_index;
	static char	character;
	static char	*message;

	if (*flag == 0)
	{
		bit_index = 7;
		character = 0;
		message = NULL;
		*flag = 1;
	}
	if (signum == SIGUSR1)
		character |= (1 << bit_index);
	bit_index--;
	if (bit_index < 0)
	{
		handle_complete_msg(character, &message, &bit_index);
		character = 0;
	}
}

void	handle_signal(int signum)
{
	static int	flag;

	perform_sig_processing(signum, &flag);
}

int	main(void)
{
	__pid_t				pid;
	char				*converted_pid;
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
