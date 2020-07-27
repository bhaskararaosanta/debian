#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int semheld = 0;

void release(int);
void request(int);

union semun {
	int val;			// value for SETVAL
	struct semid_ds *buf;		// buffer for IPC_STAT, IPC_SET
	unsigned short int *aaray;	// array for GETALL, SETALL
	struct seminfo *__buf;		// buffer for IPC_INFO
};

int main(int argc, char *argv[])
{
	int semid;
	union semun sunion;
	if(argc < 2) {
		semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
		sunion.val = 1;
		semctl(semid, 0, SETVAL, sunion);
	}
	else {
		semid = atoi(argv[1]);
		printf("using existing semaphore:%d\n", semid);
	}

	if(semid == -1) {
		printf("Semaphore request failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Successfully allocated semaphore with id:%d\n", semid);

	while(1) {
		int selection;
		printf("\nStatus: %d resources held by this process.\n", semheld);
		printf("Menu:\n");
		printf("1: Release a resource\n");
		printf("2: Request a resource\n");
		printf("3: Exit this process\n");
		printf("Your choice:");
		scanf("%d", &selection);
		switch(selection) {
		//	case 1: release(semid); break;
		//	case 2: request(semid); break;
		//	default: exit(0); break;
		}
	}

	return 0;
}


