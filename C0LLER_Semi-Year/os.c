#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int firstPipe[2];
    int secondPipe[2];
    int parentMsg;
    int childMsg;

    if(pipe(firstPipe) < 0)
    {
        exit(1);
    }
    if(pipe(secondPipe) < 0)
    {
        exit(1);
    }

    pid_t pid = fork();

    if(pid != 0)
    {
        pid_t parentPid = getpid();
        printf("Parent id: %d\n",parentPid);

        write(firstPipe[1], &parentPid, sizeof(parentPid));

        close(firstPipe[0]);
        close(firstPipe[1]);

        read(secondPipe[0], &childMsg, sizeof(childMsg));

        close(secondPipe[0]);
        close(secondPipe[1]);

        printf("I'm the parent, my child's id is: %d\n", childMsg);
        fflush(stdout);


        kill(childMsg, SIGTERM);
        kill(parentPid, SIGTERM);
    }

    else if(pid == 0)
    {
        pid_t childPid = getpid();
        printf("Child id: %d\n", childPid);

        read(firstPipe[0], &parentMsg, sizeof(parentMsg));

        close(firstPipe[0]);
        close(firstPipe[1]);

        write(secondPipe[1], &childPid, sizeof(childPid));

        close(secondPipe[0]);
        close(secondPipe[1]);

        printf("I'm the child process, my parent's id is: %d\n", parentMsg);
    }
}