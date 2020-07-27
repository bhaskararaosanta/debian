#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdlib.h>

struct shmbuf {
	int data;
	char name[30];
};

int main()
{
	struct shmbuf *shmserver;
	key_t key;
	int shmid, retshmctl, retshmdt;
	char *shmaddr;
	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", (int)key);

	/* int shmget(key_t key, size_t shmsize, int shmflg); */
	if((shmid = shmget(key, sizeof(struct shmbuf), IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmget or shmid:%d\n", shmid);

	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	if((shmserver = (struct shmbuf *)shmat(shmid, NULL, 0666)) == (struct shmbuf *) -1) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("memory where shared memory segment created:%p\n", shmserver);

	shmserver->data = 10000;
	strcpy(shmserver->name, "Embedded is great");

	printf("shared memory data:%d\n", shmserver->data);
	printf("shared memory name:%s\n", shmserver->name);

	/* int shmdt(const void *shmaddr); */
	if((retshmdt = shmdt(shmserver)) < 0) {
		perror("shmdt");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmdt:%d\n", retshmdt);

	return 0;
}
