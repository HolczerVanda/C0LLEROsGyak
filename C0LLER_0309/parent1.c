#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
pid_t fork(void);

#include <sys/types.h>
#include <sys/wait.h>
pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int* wstatus, int options);

int main(void)
{
    pid_t pid;

    if((pid==fork())<0)
    {
        perror("fork error");
    }
    else if(pid==0)
    {
        if(execl("./child.out","child",(char *)NULL)<0)
        {
            perror("execl error");
        }
    }
	if(waitpid(pid, NULL, 0)<0)
    {
        
    }

    exit(0);
}
