#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("Error en fork");
        return 1;
    }
    else if (pid == 0)
    {
        // Proceso hijo: medir tiempo de conteo
        clock_t start, end;
        double elapsed_time;

        start = clock(); // Inicia la medición del tiempo

        for (int i = 1; i <= 4000000; i++)
        {
            printf("Proceso hijo contando: %d\n", i);
        }

        end = clock(); // Finaliza la medición del tiempo
        elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Proceso hijo finalizado en %.6f segundos.\n", elapsed_time);
    }
    else
    {
        // Proceso padre: bucle infinito
        while (1)
            ;
    }

    return 0;
}
