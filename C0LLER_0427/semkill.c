#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEMKEY 280103

    int semid,nsems,rtn;
    int semflg;
    struct sembuf sembuf, *sop;
    union semun{int val;
    struct semid_ds *buf;
	unsigned short *array;}arg;
    int cmd;

main()
{
    nsems = 1;
    semflg = 00666 | IPC_CREAT;
    semid = semget (SEMKEY, nsems, semflg);
    if (semid < 0 ) {perror(" semget error"); exit(0);}
    else printf("\n semid: %d ",semid);
    printf ("\n");

    cmd = IPC_RMID;
    rtn = semctl(semid,0, cmd, arg);
    printf("\n Kill rtn: %d ",rtn);
    printf("\n");

}