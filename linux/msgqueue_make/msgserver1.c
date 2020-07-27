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
} msgserver = {1000, "Embedded is good"};

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

	/* int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg); */
	if((retmsgsnd = msgsnd(msgid, &msgserver, sizeof(struct msgbuf), 0)) < 0) {
		MSG("msgsnd");
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);
	


	return 0;
}

	
