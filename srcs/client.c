#include "../libft/libft.h"

#include <unistd.h>
#include <signal.h>
#include <stdio.h> // apagar quando já não precisar

int main(int argc, char **argv)
{
    int signum;
    char *msg;

    if (argc == 3)
    {
        signum = ft_atoi(argv[1]);
        msg = argv[2];
        printf("Signum: %i\n", signum); // substituir pela minha ft_printf()
        printf("Message: %s\n", msg); // substituir pela minha ft_printf()
        return (0);
    }
    else
    {
        printf("Number of parameters is not two, terminating..."); // substituir pela minha ft_printf()
        return (1);
    }
}