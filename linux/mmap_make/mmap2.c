#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

int main()
{
	struct stat mystat;
	int fd, retw, retr, retc, retfstat;
	char *mmapaddr, wbuf[30] = "Embedded is great", rbuf[30];
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar2", O_CREAT | O_RDWR, 0666)) < 0) {
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
	/* int fstat(int fd, struct stat *buf); */
	if((retfstat = fstat(fd, &mystat)) < 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat:%d\n", retfstat);
	/* void *mmap(const void *addr, size_t size, int prot, int flags, int fd, off_t offset); */
	mmapaddr = mmap(NULL, mystat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(mmapaddr == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("memory where file is mapped:%p\n", mmapaddr);
	printf("first data character available in memory:%c\n", *mmapaddr);
	/* char *strncpy(char *dest, const char *src, size_t n); */
	strncpy(mmapaddr, "Dladccdc", sizeof("Dladccdc"));

	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retr = read(fd, rbuf, sizeof(rbuf))) < 0) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of read syscall:%d\n", retr);
	printf("data read through file descriptor:%s\n", rbuf);
	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);

	return 0;
}
