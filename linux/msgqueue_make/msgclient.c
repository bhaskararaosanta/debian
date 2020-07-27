#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <time.h>

struct msgbuf {
	long mtype;
	char mtext[30];
} msgclient;

int main()
{
	int msgid, retmsgctl, retmsgsnd, retmsgrcv;
	struct msqid_ds mystat;
	key_t key;
	/* key_t ftok(const char *pathname, int proj_id); */
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
	/* ssize_t msgrcv(int msgid, void *msgp, size_t msgsz, long mtype, int msgflg); */
	if((retmsgrcv = msgrcv(msgid, &msgclient, sizeof(struct msgbuf), 1000, 0666)) < 0) {
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgrcv syscall:%d\n", retmsgrcv);
	printf("message number in queue:%ld\n", msgclient.mtype);
	printf("actual message in queue:%s\n", msgclient.mtext);
	/* int msgctl(int msgid, int cmd, struct msqid_ds *buf); */
	if((retmsgctl = msgctl(msgid, IPC_STAT, &mystat)) < 0) {
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgctl syscall:%d\n", retmsgctl);

	printf(" ******* printing message queue details *******\n");
	printf("Time of last msgsnd(2)		:%s\n", ctime(&mystat.msg_stime));
	printf("Time of last msgrcv(2)		:%s\n", ctime(&mystat.msg_rtime));
	printf("Time of last change		:%s\n", ctime(&mystat.msg_ctime));
	printf("Current number of bytes in queue (nonstandard)	:%d\n", mystat.__msg_cbytes);
	printf("Current number of messages in queue		:%d\n", mystat.msg_qnum);
	printf("Maximum number of bytes allowed in queue	:%d\n", mystat.msg_qbytes);
	printf("PID of last msgsnd(2)		:%d\n", mystat.msg_lspid);
	printf("PID of last msgrcv(2)		:%d\n", mystat.msg_lrpid);
	printf("Key supplied to msgget(2)	:%d\n", mystat.msg_perm.__key);
	printf("Effective UID of owner		:%d\n", mystat.msg_perm.uid);
	printf("Effective GID of owner		:%d\n", mystat.msg_perm.gid);
	printf("Effective UID of creator	:%d\n", mystat.msg_perm.cuid);
	printf("Effective GID of creator	:%d\n", mystat.msg_perm.cgid);
	printf("Permissions			:%o\n", mystat.msg_perm.mode);
	printf("Sequence number			:%d\n", mystat.msg_perm.__seq);

	printf(" ******** end of printing message queue details ******\n");

	return 0;
}
