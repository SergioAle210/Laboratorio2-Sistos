#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("Proceso padre (PID: %d)\n", getpid());

    for (int i = 0; i < 4; i++)
    {
        fork();
        printf("Proceso (PID: %d, PPID: %d) en iteración %d\n", getpid(), getppid(), i);
    }

    return 0;
}
