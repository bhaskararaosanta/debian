#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

struct msgbuf {
	long mtype;
	char mtext[50];
} msgserver = {3000, "Embedded is great"};

int main()
{
	int msgid, retmsgsnd, retmsgctl;
	key_t key;
	printf("size of struct msgbuf:%d\n", sizeof(struct msgbuf));
	printf("size of int:%d\n", sizeof(int));
	printf("size of long int:%d\n", sizeof(long int));
	printf("size of long long int:%d\n", sizeof(long long int));

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

	/* int msgsnd(int msgid, const void *msgptr, size_t msgsz, int flags); */
	if((retmsgsnd = msgsnd(msgid, &msgserver, sizeof(struct msgbuf), IPC_NOWAIT)) < 0) {
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);

	printf("mtype data written to message queue:%ld\n", msgserver.mtype);
	printf("mtext data written to message queue:%s\n", msgserver.mtext);

	
	return 0;
}	
