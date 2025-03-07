#include "../libft/libft.h"

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h> // apagar quando já não precisar

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

void	handle_signal(int signum)
{
	static int	bit_index = 7;
	static char	character = 0;
	static char	*message = NULL;

	if (signum == SIGUSR1)
		character |= (1 << bit_index);
	bit_index--;
	if (bit_index < 0)
	{
		if (character == '\0')
		{
			printf("%s\n", message); // substituir pela minha ft_printf()
			free(message);
			message = NULL;
		}
		else
			append_char_to_msg(character, &message);
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

	while (1)
	{
		pause();
	}

    return (0);
}