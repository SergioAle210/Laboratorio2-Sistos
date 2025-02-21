#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid_hijo, pid_nieto, pid_bisnieto;
    clock_t start, end;
    double elapsed_time;

    // Capturar el tiempo antes del fork inicial
    start = clock();

    // Primer fork: Crear el proceso hijo
    pid_hijo = fork();

    if (pid_hijo == 0)
    { // Proceso hijo
        pid_nieto = fork();

        if (pid_nieto == 0)
        { // Proceso nieto
            pid_bisnieto = fork();

            if (pid_bisnieto == 0)
            { // Proceso bisnieto
                // El bisnieto ejecuta un ciclo de un millón de iteraciones
                for (int i = 0; i < 1000000; i++)
                {
                    printf("Bisnieto - Iteración: %d\n", i);
                };
            }
            else
            { // Proceso nieto espera al bisnieto y ejecuta su propio ciclo
                wait(NULL);
                for (int i = 0; i < 1000000; i++)
                {
                    printf("Nieto - Iteración: %d\n", i);
                };
            }
        }
        else
        { // Proceso hijo espera al nieto y ejecuta su propio ciclo
            wait(NULL);
            for (int i = 0; i < 1000000; i++)
            {
                printf("Hijo - Iteración: %d\n", i);
            };
        }
    }
    else
    { // Proceso padre espera al hijo
        wait(NULL);

        // Capturar el tiempo después de la ejecución
        end = clock();
        elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Desplegar el tiempo total de ejecución
        printf("Tiempo de ejecución: %f segundos\n", elapsed_time);
    }

    return 0;
}
