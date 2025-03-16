#include "../libft/libft.h"

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h> // apagar quando já não precisar

// Flag to track phase of signal conversion
int	g_recieved_msg_len = 0;

typedef struct s_state {
	int		length;
	int		len_bit_index;
	int		msg_bit_index;
	int		current_char;
	char	*buffer;
} t_state;

// Process the first 32 bits sent by the client
void	process_length_bit(int signum, int *bit_index, int *length)
{
	if (signum == SIGUSR1)
	{
		*length |= (1 << *bit_index);
	}
	else
	{
		*length &= ~(1 << *bit_index);
	}
	(*bit_index)--;
	if (*bit_index < 0)
		g_recieved_msg_len = *length;
}

void	alloc_message_buffer(char **message, int length)
{
	*message = (char*)malloc((length + 1) * sizeof(char));
	if (!*message)
		exit(1);
	(*message)[length] = '\0';
	
}

void	process_char_bit(int signum, int *bit_index, char *character)
{
	if (signum == SIGUSR1)
		*character |= (1 << *bit_index);
	else
		*character &= ~(1 << *bit_index);
	(*bit_index)--;
}

void	append_char_to_msg(char character, int current_index, char **msg_ptr)
{
	(*msg_ptr)[current_index] = character;
}

void	handle_complete_msg(char **message)
{
	ft_putstr_fd(*message, 1);
	ft_putchar_fd('\n', 1);
	free(*message);
	g_recieved_msg_len = 0;
	*message = NULL;
}

void	process_length(int signum, char **message)
{
	static int	bit_index = 31;
	static int	message_length = 0;

	process_length_bit(signum, &bit_index, &message_length);
	if (g_recieved_msg_len > 0)
	{
		printf("Recieved the len: %i\n", message_length);
		alloc_message_buffer(message, message_length);
	}
}
void	process_message(int signum, char **message)
{
	static int	bit_index = 7;
	static char	character = 0;
	static int	current_char_index = 0;

	process_char_bit(signum, &bit_index, &character);
	if (bit_index < 0)
	{
		append_char_to_msg(character ,current_char_index, message);
		current_char_index++;
		character = 0;
		if (current_char_index == g_recieved_msg_len)
		{
			handle_complete_msg(message);
			current_char_index = 0;
		}
		bit_index = 7;
	}
}

void	handle_signal(int signum)
{
	static char	*message = NULL;

	if (g_recieved_msg_len == 0)
		process_length(signum, &message);
	else
		process_message(signum, &message);
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_putstr_fd(ft_itoa(pid), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
