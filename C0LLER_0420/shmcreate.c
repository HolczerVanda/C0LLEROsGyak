#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define 280103

int main()
{
	int shmid;
	key_t key;
	int size=512;
	int shmflg;

	key= SHMKEY;

	shmflg=0;
	if((shmid=shmget(key, size, shmflg))<0
	{
		perror("The shmget() system-call wasn't successful!\n");
		exit(-1);
	}
	else printf("There is already a shm segment like that!\n");

	printf("The segment's identifier: %d\n", shmid);

	exit(0);
}
