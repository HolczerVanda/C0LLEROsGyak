#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 280103

struct msgbuf1
    {
        long mtype;
        char mtext[512];
    } sendbuf, *msgp;

int main()
{
    int msgid;
	key_t key;
	int msgflg;
	int ret, msgsz;
	
	key = MSGKEY;
	msgflg = 00666 | IPC_CREAT;
	msgid = msgget(key, msgflg);
	
 	if (msgid == -1) {
                perror(": msgget() wasn't successful!");
                exit(-1);
        }
	printf("msgid has been created: %d, %x\n", msgid,msgid);
	
	msgp = &sendbuf;
	msgp->mtype = 1;
 	strcpy(msgp->mtext,"First message");
 	msgsz = strlen(msgp->mtext) + 1;
 	
 	ret = msgsnd(msgid,(struct msgbuf *)msgp, msgsz, msgflg);
 	
 	printf("1. msgsnd() gave: %d\n", ret);
	printf("The sent message: %s\n", msgp->mtext);
	
	strcpy(msgp->mtext,"Second message");
	msgsz       = strlen(msgp->mtext) + 1;
	
	ret = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);
	
	printf("2. msgsnd gave: %d\n", ret);
	printf("The sent message: %s\n", msgp->mtext);

	exit(0);
}

