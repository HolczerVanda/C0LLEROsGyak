#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>


unsigned int interrupts = 0;
void InterruptHandler(int sig);
void QuitHandler(int sig);

int main(void) {

    if(signal(SIGINT,InterruptHandler) == SIG_ERR)
    {
        printf("Nem sikerült handlert allitani a(z) \"SIGINT\" jelre\n");
        return 0;
    }

    if(signal(SIGQUIT, QuitHandler) == SIG_ERR)
    {
        printf("Nem sikerült handlert allitani a(z) \"SIGQUIT\" jelre\n");
        return 0;
    }

    while(interrupts < 2)
    {
        printf("Varakozas jelre...\n");
        sleep(1);
    }

    printf("Megerkezett a masodik \"SIGINT\" jel! ");

    return 0;

}

void InterruptHandler(int sig)
{
    printf("SIGINT signal: %d\n",sig);
    interrupts++;
}
void QuitHandler(int sig)
{
    printf("SIGQUIT signal: %d\n",sig);
    interrupts++;
}
