#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	struct stat mystat;
	int fd, retw, retr, retc, retfstat;
	char *mmapaddr, wbuf[30] = "Embedded is great";
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar4", O_CREAT | O_RDWR, 0666)) < 0) {
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

	/* int fstat(int fd, struct stat *mybuf); */
	if((retfstat = fstat(fd, &mystat)) < 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat syscall:%d\n", retfstat);

	/* void *mmap(void *addr, size_t length,int prot, int flags, int fd, off_t offset); */
	mmapaddr = mmap(NULL, mystat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, \
			fd, 0);
	if(mmapaddr == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("memory where file is mapped:%p\n", mmapaddr);

	/* char *strncpy(char *dest, const char *src, size_t count); */
	strncpy(mmapaddr, "Fncfeefe", sizeof("Fncfeefe"));

	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);

	return 0;
}
	
