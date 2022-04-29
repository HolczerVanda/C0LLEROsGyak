#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEMKEY 280103

    int semid,nsems,rtn;
    unsigned nsops;
    int semflg;
    struct sembuf sembuf, *sop;

main()
{
    nsems = 1;
    semflg = 00666 | IPC_CREAT;
    semid = semget (SEMKEY, nsems, semflg);
    if (semid < 0 ) {perror(" semget error"); exit(0);}
    else printf("\n semid: %d ",semid);
    printf ("\n");
    nsops = 1;
    sembuf.sem_num = 0;
    sembuf.sem_op = 1;
    sembuf.sem_flg = 0666;
    sop = &sembuf;
    rtn = semop(semid, sop, nsops);
    printf("\n up rtn: %d ",rtn);
    printf("\n");
}