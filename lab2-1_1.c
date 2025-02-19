#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Proceso inicial PID: %d\n", getpid());

    fork(); // Primer fork
    fork(); // Segundo fork
    fork(); // Tercer fork
    fork(); // Cuarto fork

    printf("Proceso PID: %d, Padre PID: %d\n", getpid(), getppid());

    return 0;
}
