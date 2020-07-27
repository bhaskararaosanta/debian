#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main()
{
	//struct timespec ts;
	struct stat mystat;
	int fd, retw, retr, retc, retlseek, retfstat;
	char wbuf[30] = "Embedded is great", rbuf[30];

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar5", O_CREAT | O_WRONLY, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);

	/* ssize_t write(int fd, const void *buf, size_t count); */
	if((retw = write(fd, wbuf, sizeof(wbuf))) < 0) {
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of write syscall:%d\n", retw);

	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar5", O_RDWR, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);

	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retr = read(fd, rbuf, sizeof(rbuf))) < 0) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of read syscall:%d\n", retr);
	printf("data read through fd before lseek:%s\n", rbuf);

	/* int fstat(int fd, struct stat *buf); */
	//if((retfstat = fstat(fd, &mystat)) < 0) {
	/* int stat(const char *pathname, struct stat *buf); */
	if((retfstat = stat("bhaskar5", &mystat)) < 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat syscall:%d\n", retfstat);
	
	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);

	printf("******** printing file stats started ********\n");
	printf("ID of device contan file:%d\n", mystat.st_dev);
	printf("inode number		:%d\n", mystat.st_ino);
	printf("file type and mode	:%o\n", mystat.st_mode);
	printf("number of hard links	:%d\n", mystat.st_nlink);
	printf("user ID of owner	:%d\n", mystat.st_uid);
	printf("group ID of owner	:%d\n", mystat.st_gid);
	printf("total size in bytes	:%d\n", mystat.st_size);
	printf("block size for fs I/O	:%d\n", mystat.st_blksize);
	printf("no. of 512B blocks	:%d\n", mystat.st_blocks);
	printf("\n");
	printf("Time of last access	:%s\n", ctime(&(mystat.st_atim)));
	printf("Time of last modificati	:%s\n", ctime(&(mystat.st_mtim)));
	printf("Time of last stat change:%s\n", ctime(&(mystat.st_ctim)));

	printf("******* end of file stats printing **********\n");

	return 0;
}
