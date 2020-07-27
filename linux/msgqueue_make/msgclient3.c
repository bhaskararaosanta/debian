#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

struct msgbuf {
	long mtype;
	char mtext[50];
} msgclient;

int main()
{
	int msgid, retmsgrcv, retmsgctl;
	key_t key;
	
	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", (int)key);

	/* int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("return value of message id:%d\n", msgid);

	/* ssize_t msgrcv(int msgid, void *msgptr, size_t msgsz, long mtype, int flags); */
	if((retmsgrcv = msgrcv(msgid, &msgclient, sizeof(struct msgbuf), 3000, IPC_NOWAIT)) < 0) {
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgrcv:%d\n", retmsgrcv);

	printf("mtype data received from message queue:%ld\n", msgclient.mtype);
	printf("mtext data received from message queue:%s\n", msgclient.mtext);

	
	return 0;
}	
