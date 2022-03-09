#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int status;

    if((status=system("date"))<0)
    {
        perror("system() error");
    }
    if(WIFEXITED(status))
    {
        printf("Normalis befejezodes, visszaadott ertek = %d\n", WEXITSTATUS(status));
    }

    if((status=system("C0LLER"))<0)
    {
        perror("system() error");
    }
    if(WIFEXITED(status))
    {
        printf("Normalis befejezodes, visszaadott ertek = %d\n", WEXITSTATUS(status));
    }

    exit(0);
}
