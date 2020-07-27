#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <time.h>

struct shmbuf {
	int account;
	char name[30];
};

int main()
{
	struct shmid_ds mybuf;
	struct shmbuf *shmclient;
	int key, shmid, retshmctl;
	
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
	if((shmclient = (struct shmbuf *)shmat(shmid, NULL, SHM_EXEC)) == (struct shmbuf *) -1) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("address where shared memory attached:%p\n", shmclient);

	printf("account number received through client:%d\n", shmclient->account);
	printf("name recevived through client:%s\n", shmclient->name);
	
	/* int shmctl(int shmid, int cmd, struct shmid_ds *buf); */
	if((retshmctl = shmctl(shmid, IPC_STAT, &mybuf)) < 0) {
		perror("shmctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmctl syscall:%d\n", retshmctl);

	printf("********** printing shared memory stats ********** \n");
	printf("Size of segment (bytes)		:%d\n", mybuf.shm_segsz);
	printf("Last attach time		:%s", ctime(&mybuf.shm_atime));
	printf("Last detach time		:%s", ctime(&mybuf.shm_dtime));
	printf("Last change time		:%s", ctime(&mybuf.shm_ctime));
	printf("PID of creator			:%d\n", mybuf.shm_cpid);
	printf("PID of last shmat(2)/shmdt(2)	:%d\n", mybuf.shm_lpid);
	printf("No. of current attaches		:%d\n", mybuf.shm_nattch);
	printf("Key supplied to shmget(2)	:%d\n", mybuf.shm_perm.__key);
	printf("Effective UID of owner		:%d\n", mybuf.shm_perm.uid);
	printf("Effective GID of owner		:%d\n", mybuf.shm_perm.gid);
	printf("Effective UID of creator	:%d\n", mybuf.shm_perm.cuid);
	printf("Effective GID of creator	:%d\n", mybuf.shm_perm.cgid);
	printf("Permissions + flags		:%o\n", mybuf.shm_perm.mode);
	printf("Sequence number			:%d\n", mybuf.shm_perm.__seq);
	printf("******** End of printing stats ***********\n");

	return 0;
}
