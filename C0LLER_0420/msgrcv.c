#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 280103

struct msgbuf1
{
	long mtype;
	char mtext[512];
} recvbuf, *msgp;
struct msqid_ds ds, *buf;

main()
{
	int msgid;
	key_t key;
	int mtype, msgflg;
	int ret, msgsz;

	key = MSGKEY;
	msgflg = 00666 | IPC_CREAT | MSG_NOERROR;

	msgid = msgget(key, msgflg);
 	if (msgid == -1) {
                perror("msgget() wasn't successful");
                exit(-1);
        }
	printf("msgid: %d\n",msgid);

	msgp = &recvbuf;
	buf = &ds;
	msgsz = 20;
	mtype = 0;

	ret = msgctl(msgid, IPC_STAT, buf);
	printf("Number of messages: %d\n", buf->msg_qnum);

	while (buf->msg_qnum) {
		ret = msgrcv(msgid,(struct msgbuf *)msgp, msgsz, mtype, msgflg);
		printf("msgrcv() gave: %d, received message: %s\n",ret, msgp->mtext);
		ret = msgctl(msgid, IPC_STAT, buf);
	}

	exit(0);
}
