#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <time.h>

struct shmbuf {
	int num;
	char data[30];
};

int main()
{
	struct shmid_ds mybuf;
	int shmid, retshmctl, retshmdt;
	struct shmbuf *shmclient;
	key_t key;
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
	printf("return value of shmid:%d\n", shmid);
	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	if((shmclient = (struct shmbuf *)shmat(shmid, NULL, 0666)) == (struct shmbuf *) -1) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("memory where shared memory segment attached:%p\n", shmclient);
	printf("number attached to shared memory using server:%d\n", shmclient->num);
	printf("data read from shared memory:%s\n", shmclient->data);

	/* int shmctl(int shmid, int cmd, struct shmid_ds *buf); */
	if((retshmctl = shmctl(shmid, IPC_STAT, &mybuf)) < 0) {
		perror("shmctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmctl syscall:%d\n", retshmctl);

	printf("****** printing shared memory statistics **********\n");
	printf("Size of segment (bytes)		:%d\n", mybuf.shm_segsz);
	printf("Last attach time		:%s\n", ctime(&mybuf.shm_atime));
	printf("Last detach time		:%s\n", ctime(&mybuf.shm_dtime));
	printf("Last change time		:%s\n", ctime(&mybuf.shm_ctime));
	printf("PID of creator			:%d\n", mybuf.shm_cpid);
	printf("PID of last shmat(2)/shmdt(2)	:%d\n", mybuf.shm_lpid);
	printf("No. of current attaches		:%d\n", mybuf.shm_nattch);
	printf("Key supplied to shmget(2)	:%d\n", mybuf.shm_perm.__key);
	printf("Effective UID of owner		:%d\n", mybuf.shm_perm.uid);
	printf("Effective GID of owner		:%d\n", mybuf.shm_perm.gid);
	printf("Effective UID of creator	:%d\n", mybuf.shm_perm.cuid);
	printf("Effective GID of creator	:%d\n", mybuf.shm_perm.cgid);
	printf("Permissions + SHM_DEST and SHM_LOCKED flags	:%o\n", mybuf.shm_perm.mode);
	printf("Sequence number			:%d\n", mybuf.shm_perm.__seq);
	printf("******** end of printing shared memory stats ***********\n");

	/* int shmdt(const void *shmaddr); */
	if((retshmdt = shmdt(shmclient)) < 0) {
		perror("shmdt");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmdt syscall:%d\n", retshmdt);

	return 0;
}
