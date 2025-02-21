#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;

    // Primer fork
    pid1 = fork();
    if (pid1 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid1 == 0)
    {
        printf("Soy el proceso hijo (*)\n");
        // Proceso hijo 1 ejecuta ipc con símbolo '*'
        execl("./ipc", "./ipc", "5", "*", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    }

    // Segundo fork
    pid2 = fork();
    if (pid2 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid2 == 0)
    {
        printf("Soy el proceso padre (#)\n");
        // Proceso hijo 2 ejecuta ipc con símbolo '#'
        execl("./ipc", "./ipc", "5", "#", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    }

    // Esperar a ambos hijos
    wait(NULL);
    wait(NULL);

    return 0;
}