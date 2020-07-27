#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
	int val;		// value for SETVAL
	struct semid_ds *buf;	// buffer for IPC_STAT and IPC_SET
	unsigned short *array;	// array for GETALL and SETALL
};

struct sembuf p = {0, -1, SEM_UNDO};
struct sembuf v = {0, +1, SEM_UNDO};

int main()
{
	key_t key;
	int pid, semid, retsemctl;

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
	printf("return value of semid:%d\n", semid);

	union semun u;
	u.val = 1;
	if((retsemctl = semctl(semid, 0, SETVAL, u)) < 0) {
		perror("semctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of semctl:%d\n", semctl);
	
	pid = fork();
	if(pid < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid) {
		int i;
		char *s = "abcdefgh";
		int l = strlen(s);
		for(i = 0; i < l; i++) {
			/* int semop(int semid, struct sembuf *sops, size_t nsops); */
			if(semop(semid, &p, 1) < 0) {
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			putchar(s[i]);
			fflush(stdout);
			sleep(rand() % 2);
			putchar(s[i]);
			fflush(stdout);
			if(semop(semid, &v, 1) < 0) {
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			sleep(rand() % 2);
		}
	}
	else {
		int i;
		char *s = "ABCDEFGH";
		int l = strlen(s);
		for(i = 0; i < l; i++) {
			/* int semop(int semid, struct sembuf *sops, size_t nsops); */
			if(semop(semid, &p, 1) < 0) {
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			putchar(s[i]);
			fflush(stdout);
			sleep(rand() % 2);
			putchar(s[i]);
			fflush(stdout);
			if(semop(semid, &v, 1) < 0) {
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			sleep(rand() % 2);
		}
	}

	return 0;
}




	

