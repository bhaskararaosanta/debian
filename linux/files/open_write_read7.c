#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct stat mystat;
	int fd, retw, retr, retlseek, retfstat, retc;
	char wbuf[30] = "Embedded is great", rbuf[30];
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar7", O_CREAT | O_WRONLY, 0666)) < 0) {
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

	/* int fstat(int fd, struct stat 8buf); */
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

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar7", O_CREAT | O_RDONLY, 0666)) < 0) {
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

	printf("data read through file descriptor:%s\n", rbuf);

	/* int close(int fd): */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);
	
	printf("******** printing file statistics *********\n");
	printf("ID of device containing file	:%d\n", mystat.st_dev);
	printf("Inode number			:%d\n", mystat.st_ino);
	printf("file type and mode		:%o\n", mystat.st_mode);
	printf("Number of hard links		:%d\n", mystat.st_nlink);
	printf("User ID of owner		:%d\n", mystat.st_uid);
	printf("Group ID of owner		:%d\n", mystat.st_gid);
	printf("Total size in bytes		:%d\n", mystat.st_size);
	printf("Block size of file system I/O	:%d\n", mystat.st_blksize);
	printf("Number of 512B blocks allocated	:%d\n", mystat.st_blocks);
	printf("******** End of printing statistics *********\n");

	return 0;
}
