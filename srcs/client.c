#include "../libft/libft.h"

#include <unistd.h>
#include <signal.h>
#include <stdio.h> // apagar quando já não precisar

// pegar nesta função da piscine e adicionar ao libft
int ft_put_nbr_base(int nbr, char *base)
{
    printf("%s\n", base); // para nao dar erro ao compilar para já
    return (nbr); // para nao dar erro ao compilar para já
}

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