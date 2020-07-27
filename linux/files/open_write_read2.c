#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd, retw, retr, retc, retfstat;
	char wbuf[30] = "Embedded is great", rbuf[30];
	struct stat mystat;
	/* int open(const char *pathaname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_WRONLY, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);
	/* ssize_t write(int fd, const void *buf, size_t size); */
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
	if((fd = open("bhaskar", O_CREAT | O_RDONLY, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);
	/* ssize_t read(int fd, void *buf, size_t size); */
	if((retr = read(fd, rbuf, sizeof(rbuf))) < 0) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of read syscall:%d\n", retr);
	
	/* int fstat(int fd, struct stat *buf); */
	if((retfstat = fstat(fd, &mystat)) < 0) {
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
	printf("data read through file descriptor:%s\n", rbuf);

	printf("******* printing file stats *********\n");
	printf("ID of device contains file	:%d\n", mystat.st_dev);
	printf("Inode number		:%d\n", mystat.st_ino);
	printf("file type and mode	:%o\n", mystat.st_mode);
	printf("number of hard links	:%d\n", mystat.st_nlink);
	printf("user ID of owner	:%d\n", mystat.st_uid);
	printf("group ID of owner	:%d\n", mystat.st_gid);
	printf("total size in bytes	:%d\n", mystat.st_size);
	printf("blocksize for file sys	:%d\n", mystat.st_blksize);
	printf("no of 512B blocks alloc	:%d\n", mystat.st_blocks);
	printf("******** end of printing stats ********\n");

	return 0;
}
