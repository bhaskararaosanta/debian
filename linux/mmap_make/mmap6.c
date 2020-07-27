#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	char *mmapaddr, wbuf[30] = "Embedded is great", rbuf[30];
	int fd, retw, retr, retc, retfstat;
	struct stat mystat;

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar6", O_CREAT | O_RDWR, 0666)) < 0) {
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

	/* int fseek(int fd, struct stat *buf); */
	if((retfstat = fstat(fd, &mystat)) < 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat:%d\n", retfstat);

	/* void *mmap(void *mmapaddr, size_t length, int prot, int flags, int fd, loff_t offset); */
	mmapaddr = mmap(NULL, mystat.st_size, PROT_READ | PROT_WRITE, \
			MAP_SHARED, fd, 0);
	if(mmapaddr == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("memory location where file is mapped:%p\n", mmapaddr);

	/* void *strncpy(char *dest, const char *src, size_t size); */
	strncpy(mmapaddr, "FNCFEEFE", sizeof("FNCFEEFE"));

	return 0;
}
