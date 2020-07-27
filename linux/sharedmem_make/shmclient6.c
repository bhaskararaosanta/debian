#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

struct shmbuf {
	int account;
	char name[30];
};

int main()
{
	struct shmbuf *shmclient;
	int shmid, retshmctl, retshmdt;
	char *shmaddr;
	key_t key;

	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key value:%d\n", (int)key);

	/* int shmget(key_t key, size_t size, int shmflg); */
	if((shmid = shmget(key, sizeof(struct shmbuf), IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("return value of shared memory id:%d\n", shmid);

	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	if((shmclient = (struct shmbuf *)shmat(shmid, NULL, 0)) == (struct shmbuf *)-1) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("memory where shared memory assigned:%p\n", shmclient);

	printf("account number written to shared memory:%d\n", shmclient->account);
	printf("name written to shared memory:%s\n", shmclient->name);

	/* int shmdt(const void *shmaddr); */
	if((retshmdt = shmdt(shmclient)) < 0) {
		perror("shmdt");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmdt:%d\n", retshmdt);

	return 0;
}
