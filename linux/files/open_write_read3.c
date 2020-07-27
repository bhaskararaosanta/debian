#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd, retw, retr, retc, retfstat, retlseek;
	struct stat mystat;
	char wbuf[30] = "Embedded is great", rbuf[30];
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_WRONLY, 0666)) < 0) {
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
	/*int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDONLY, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);
	/* ssize_t read(int fd, void *buf, size_t countr); */
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
	printf(" **************** file statistics printing started *************\n");
	printf("ID of device containing file	:%d\n", mystat.st_dev);
	printf("inode number			:%d\n", mystat.st_ino);
	printf("file type and mode		:%o\n", mystat.st_mode);
	printf("number of hard links		:%d\n", mystat.st_nlink);
	printf("user ID of owner		:%d\n", mystat.st_uid);
	printf("group ID of owner		:%d\n", mystat.st_gid);
	printf("total size, in bytes		:%d\n", mystat.st_size);
	printf("blocksize of file system I/O 	:%d\n", mystat.st_blksize);
	printf("number of 512B blocks allocated	:%d\n", mystat.st_blocks);

	printf(" ************** file stats printing end ***********************\n");

	return 0;
}
