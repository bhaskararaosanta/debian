#include <stdio.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

struct shmbuf {
	int number;
	char name[30];
};

int main()
{
	struct shmbuf *shmclient;
	int shmid, key, retshmdt;
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
       if((shmclient = (struct shmbuf *)shmat(shmid, NULL, SHM_EXEC)) == (struct shmbuf *) -1) {
       perror("shmat");
       exit(EXIT_FAILURE);
       }
       printf("address where shared memory segment attached:%p\n", shmclient);

       printf("number stored at shared memory segment:%d\n", shmclient->number);
       printf("data stored at shared memory segentt:%s\n", shmclient->name);

       /* int shmdt(const void *shmaddr); */
       if((retshmdt = shmdt(shmclient)) < 0) {
	       perror("shmdt");
	       exit(EXIT_FAILURE);
       }
       printf("return value of shmdt:%d\n", retshmdt);

       return 0;
}
