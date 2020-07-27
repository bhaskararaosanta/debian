#include <stdio.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

struct shmbuf {
	int number;
	char name[30];
};

int main()
{
	struct shmbuf *shmserver;
	int shmid, key;
	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", key);

	/* int shmget(key_t key, size_t size, int shmflg); */
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
       printf("address where shared memory segment attached:%p\n", shmserver);
	shmserver->number = 500;
	/* char *strcpy(char *dest, const char *src); */
	strcpy(shmserver->name, "Bhaskar is good");
		
       return 0;
}
