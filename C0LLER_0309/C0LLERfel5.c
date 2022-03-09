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

    if((pid=fork())<0) perror("fork hiba");
        else if(pid==0)
                exit(7);
    if(wait(&status)!=pid) perror("wait hiba");
    if(WIFEXITED(status))
            printf("Normalis befejezodes, visszaadott ertek= %d\n", WEXITSTATUS(status));
            
     if((pid=fork())<0) perror("fork hiba");
        else if(pid==0)
                abort();
    
    if((wait()
    
}
