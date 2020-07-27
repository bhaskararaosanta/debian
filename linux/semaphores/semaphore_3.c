#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
	unsigned short val;
	struct semid_ds *buf;
	short *array;
};

struct sembuf p = {0, -1, SEM_UNDO};
struct sembuf v = {0, +1, SEM_UNDO};

int main()
{
	key_t key;
	int pid, semid, retsemctl, retsemop;

	union semun u;
	u.val = 1;

	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", (int)key);

	/* int semget(key_t key, int nsems, int semflg); */
	if((semid = semget(key, 1, IPC_CREAT | 0666)) < 0) {
		perror("semget");
		exit(EXIT_FAILURE);
	}
	printf("return value of semget:%d\n", semid);

	/* int semctl(int semid, int semnum, int cmd, ...); */
	if((retsemctl = semctl(semid, 0, SETVAL, u)) < 0) {
		perror("semctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of semctl:%d\n", retsemctl);

	if((pid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0) {
		int i;
		char *s = "abcdefgh";
		int l = strlen(s);
		for(i = 0; i < l; i++) {
			/* int semop(int semid, struct sembuf *sops, size_t nsops); */
			if((retsemop = semop(semid, &p, 1)) < 0) {
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			printf("return valie of semop-p from child:%d\n", retsemop);
			printf("%c", s[i]);
			fflush(stdout);
			sleep(1);
			printf("%c", s[i]);
			fflush(stdout);
			if((retsemop = semop(semid, &v, 1)) < 0) {
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			printf("return value of semop-v from child:%d\n", retsemop);
		}
	}
	else {
		int i;
		char *s = "ABCDEFGH";
		int l = strlen(s);
		for(i = 0; i < l; i++) {
			/* int semop(int semid, struct sembuf *sops, size_t nsops); */
			if((retsemop = semop(semid, &p, 1)) < 0) {
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			printf("return valie of semop-p from parent:%d\n", retsemop);
			printf("%c", s[i]);
			fflush(stdout);
			sleep(1);
			printf("%c", s[i]);
			fflush(stdout);
			if((retsemop = semop(semid, &v, 1)) < 0) {
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			printf("return valie of semop-v from parent:%d\n", retsemop);
		}
	}

	return 0;
}
