#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


/* struct sembuf {
	unsigned short sem_num;	// semaphore value
	short sem_op;		// semaphore operation
	short sem_flg;		// operation flags
} */

struct sembuf p = {0, -1, SEM_UNDO};
struct sembuf v = {0, +1, SEM_UNDO};

union semun {
	int val;		// value for SETVAL
	struct semid_ds *buf;	// buffer for IPC_STAT and IPC_SET
	unsigned short *array;	// Array for GETALL and SETALL
	struct seminfo *__buf;	// buffer for IPC_INFO
};

int main()
{
	int cpid, semid, retsemop, retsemctl;
	struct semid_ds buf;
	key_t key;

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

	/* int semctl(int semid, int semnum, int cmd, ...); */
	if((retsemctl = semctl(semid, 0, SETVAL, u)) < 0) {
		perror("semctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of semctl:%d\n", retsemctl); 

	cpid = fork();
	if(cpid < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(cpid == 0) {
		//printf("I am in child process\n");
		char strchild[20] = "abcdefgh";
		int i;
		for(i = 0; strchild[i] != '\0'; i++) {
			semop(semid, &p, 1);
			printf("%c", strchild[i]);
			fflush(stdout);
			sleep(1);
			printf("%c", strchild[i]);
			fflush(stdout);
			semop(semid, &v, 1);
		}
	}
	else {
		//printf("I am in parent process\n");
		char strparent[20] = "ABCDFGH";
		int i;
		for(i = 0; strparent[i] != '\0'; i++) {
			semop(semid, &p,1);
			printf("%c", strparent[i]);
			fflush(stdout);
			sleep(1);
			printf("%c", strparent[i]);
			fflush(stdout);
			semop(semid, &v, 1);
		}
	}
	
	return 0;
}

