#include <unistd.h>
#include <stdio.h> // apagar quando já não precisar

int main (void)
{
    __pid_t pid;

    pid = getpid();
    printf("%i\n", pid); // substituir pela minha ft_printf()

    return (0);
}