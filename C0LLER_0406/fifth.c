#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void kezelo(int i)
    {
        printf("Signal kezeles: %d\n", i);
        return;
    }

int main(void)
{
    printf("PID=%d\n",getpid());
    printf("Signal kezelo atvetele: %d\n", signal(SIGTERM, &kezelo));
    while(1)
    {
        printf("lepes\n");
        sleep(3);
    }
    return 0;
}

