#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct msgbuf {
	long mtype;
	char mtext[30];
} msgserver = {1000, "Embedded is great"};

int main()
{
	key_t key;
	int msgid, retmsgsnd, retmsgrcv, retmsgctl;
	/* key_t ftok(const chat *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", key);
	/* int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgid:%d\n", msgid);
	/* int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg); */
	if((retmsgsnd = msgsnd(msgid, &msgserver, sizeof(struct msgbuf), 0)) < 0) {
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);

	printf("mtype written to msg queue:%ld\n", msgserver.mtype);
	printf("mchar written to msg queue:%s\n", msgserver.mtext);
	/* int msgctl(int msgid, int cmd, struct msqid_ds *buf); */
/*	if((retmsgctl = msgctl(msgid, IPC_RMID, 0)) < 0) {
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgctl:%d\n", retmsgctl);
*/

	return 0;
}
