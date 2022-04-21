#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 280103

int main()
{
	int shmid;
	key_t key;
	int size=512;
	int shmflg;
	int rtn;
	int cmd;

	struct shmid_ds shmid_ds, *buf;
	buf = &shmid_ds;
	key = SHMKEY;

	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("The shmget() system-call wasn't successful!\n");
	    exit(-1);
	}

	do
	{
		printf("\nGive the number of the command:\n");
		printf("0. IPC_STAT (status)\n");
		printf("1. IPC_RMID (delete)\n> ");
		scanf("%d",&cmd);
	}while (cmd < 0 || cmd > 1);

	switch (cmd)
	{
	    case 0:
		rtn = shmctl(shmid, IPC_STAT, buf);
		printf("Size of the segment: %d\n",buf->shm_segsz);
		printf("Last shmop() process's pid: %d\n",buf->shm_lpid);
		break;
	    case 1:
		rtn = shmctl(shmid, IPC_RMID, NULL);
		printf("Segment deleted. Error code: %d\n", rtn);
	}

	exit(0);
}
