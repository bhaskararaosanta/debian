#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

#define	MSG(X)	do {perror(X); exit(EXIT_FAILURE); }while(0);

struct msgbuf {
	long mtype;
	char mtext[30];
} msgclient;

int main()
{
	int msgid, retmsgsnd, retmsgrcv, retmsgctl;
	key_t key;
	
	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		MSG("ftok");
	}
	printf("return value of key:%d\n", key);

	/* int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
		MSG("msgget");
	}
	printf("return value of msgget:%d\n", msgid);

	/* ssize_t msgrcv(int msgid, void *msgp, size_t msgsz, long mtype, int msgflg); */
	if((retmsgrcv = msgrcv(msgid, &msgclient, sizeof(struct msgbuf), 1000, 0)) < 0) {
		MSG("msgrcv");
	}
	printf("return value of msgrcv:%d\n", retmsgrcv);

	printf("msg type received from message queue:%ld\n", msgclient.mtype);
	printf("message received from message queue:%s\n", msgclient.mtext);

	return 0;
}

	
