#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Proceso inicial PID: %d\n", getpid());

    for (int i = 0; i < 4; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            // Proceso hijo: imprime su información y sale del bucle para evitar crear más hijos
            printf("Proceso hijo PID: %d, Padre PID: %d, Iteración: %d\n", getpid(), getppid(), i);
            break; // Evita que los hijos sigan creando más procesos
        }
    }

    return 0;
}
