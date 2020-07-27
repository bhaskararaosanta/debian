#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

struct shmbuf {
	int account;
	char name[30];
};

int main()
{
	struct shmbuf *shmserver;
	int key, shmid;
	
	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", key);

	/* int shmget(key_t key, size_t shmsz, int shmflg); */
	if((shmid = shmget(key, sizeof(struct shmbuf), IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmget:%d\n", shmid);

	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	if((shmserver = (struct shmbuf *)shmat(shmid, NULL, SHM_EXEC)) == (struct shmbuf *) -1) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("address where shared memory attached:%p\n", shmserver);

	shmserver->account = 1000;
	/* char *strcpy(char *dest, const char *src); */
	strcpy(shmserver->name, "Embedded is great");
	printf("account number assigned through server:%d\n", shmserver->account);
	printf("name entered through server:%s\n", shmserver->name);

	return 0;
}
