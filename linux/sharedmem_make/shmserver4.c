#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

struct shmbuf {
	int account;
	char data[30];
};

int main()
{
	struct shmbuf *shmserver;
	key_t key;
	int shmid, retshmctl;
	char *shmaddr;
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
	printf("return value of shmid:%d\n", shmid);

	/* void *shmaddr(int shmid, const void *shmaddr, int shmflg); */
	if((shmserver = (struct shmbuf *)shmat(shmid, NULL, SHM_RND)) == (struct shmbuf *) -1) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("address where shared memory segment attached:%p\n", shmserver);

	shmserver->account = 5000;
	strncpy(shmserver->data, "Embedded is great",sizeof("Embedded is great"));

	printf("account written to shared memory:%d\n", shmserver->account);
	printf("data written to shared memory:%s\n", shmserver->data);
	
	return 0;
}
