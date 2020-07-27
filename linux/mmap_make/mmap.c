#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main()
{
	struct stat mystat;
	int fd, retw, retr, retc, retfstat;
	char *mmapaddr, wbuf[30] = "Embedded is great", rbuf[30];
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0) {
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
	/* void *mmap(void *addr, size_t size, int prot, int flags, int fd, off_t offset); */
	mmapaddr = mmap(NULL, mystat.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	if(mmapaddr == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("mapped address:%p\n", mmapaddr);
	/* char *strncpy(char *dest, const char *src, size_t n); */
	strncpy(mmapaddr, "Gmbedded", sizeof("Gmbedded"));

	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);

	return 0;
}
